// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001,2002 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/libxipc/test_finder_messenger.cc,v 1.1 2003/01/21 18:51:36 hodson Exp $"

#include "finder_module.h"

#include "libxorp/eventloop.hh"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"

#include "libcomm/comm_api.h"

#include "finder_tcp_messenger.hh"
#include "sockutil.hh"

///////////////////////////////////////////////////////////////////////////////
//
// Constants
//

static const char *program_name         = "test_finder_messenger";
static const char *program_description  = "Test carrying and execution of Xrl"
					   "and Xrl responses.";
static const char *program_version_id   = "0.1";
static const char *program_date         = "January, 2003";
static const char *program_copyright    = "See file LICENSE.XORP";
static const char *program_return_value = "0 on success, 1 if test error, 2 if internal error";

///////////////////////////////////////////////////////////////////////////////
//
// Verbosity level control
//

static bool s_verbose = false;
bool verbose()                  { return s_verbose; }
void set_verbose(bool v)        { s_verbose = v; }

#define verbose_log(x...) _verbose_log(__FILE__,__LINE__, x)

#define _verbose_log(file, line, x...)					\
do {									\
    if (verbose()) {							\
	printf("From %s:%d: ", file, line);				\
	printf(x);							\
    }									\
} while(0)

///////////////////////////////////////////////////////////////////////////////
//
// Localized Test 
//

static XrlCmdMap xrl_cmds;

const XrlCmdError
hello_cmd(const Xrl& xrl, XrlArgs*)
{
    verbose_log("received xrl %s\n", xrl.str().c_str());
    return XrlCmdError::OKAY();
}

static void
send_hello_complete(const XrlError& e, XrlArgs*, bool *success, bool* done)
{
    *done = true;
    *success = (e == XrlError::OKAY());
    verbose_log("Hello complete (success %d)\n", *success);
    return;
}

static void
send_hello(FinderTcpMessenger* fm, bool* success, bool* done)
{
    bool send_okay;

    Xrl xrl("finder", "hello");
    
    send_okay = fm->send(xrl, callback(&send_hello_complete, success, done));
    assert(true == send_okay);
}

static void
add_commands(XrlCmdMap& cmds)
{
    cmds.add_handler("hello", callback(hello_cmd));
}

static void
connect_client(EventLoop* e, FinderTcpMessenger** m, bool* failed)
{
    IPv4 ipc_addr = if_get_preferred();
    struct in_addr ia;
    ia.s_addr = ipc_addr.addr();

    int fd = comm_connect_tcp4(&ia, FINDER_TCP_DEFAULT_PORT);
    if (fd < 0) {
	fprintf(stderr, "Client failed to connect\n");
	*failed = true;
	return;
    }
    verbose_log("Client connected to server\n");
    *m = new FinderTcpMessenger(*e, fd, xrl_cmds);
}

class DummyFinder;

class FinderAttachedTcpMessenger : public FinderTcpMessenger {
public:
    FinderAttachedTcpMessenger(DummyFinder& 	finder,
			       EventLoop&   	e,
			       int		fd,
			       XrlCmdMap&	cmds)
	: FinderTcpMessenger(e, fd, cmds), _finder(finder)
    {}

    void pre_dispatch_xrl();
    void post_dispatch_xrl();
protected:
    DummyFinder& _finder;
};

class DummyFinder : public FinderTcpListenerBase {
public:
    DummyFinder(EventLoop&  e,
		IPv4	    interface,
		uint16_t    port = FINDER_TCP_DEFAULT_PORT)
	throw (InvalidPort)
	: FinderTcpListenerBase(e, interface, port), _messenger(0)
    {
	add_permitted_host(interface);
    }

    ~DummyFinder()
    {
	delete _messenger;
    }
    
    bool connection_event(int fd)
    {
	assert(0 == _messenger);
	_messenger = new FinderAttachedTcpMessenger(*this, _e, fd, xrl_cmds);
	verbose_log("Server accepted client connection\n");
	return true;
    }

    FinderTcpMessenger* messenger() { return _messenger; }

    void set_xrl_dispatcher(FinderTcpMessenger* fm)
    {
	verbose_log("Setting dispatcher to %p\n", fm);
    }
    
protected:
    FinderTcpMessenger* _messenger;
};

void
FinderAttachedTcpMessenger::pre_dispatch_xrl() {
    _finder.set_xrl_dispatcher(this);
}

void
FinderAttachedTcpMessenger::post_dispatch_xrl() {
    _finder.set_xrl_dispatcher(0);
}

static int
test_hellos(EventLoop&e,
	    FinderTcpMessenger* src,
	    FinderTcpMessenger* dst)
{
    bool timeout_flag = false;
    XorpTimer timeout = e.set_flag_after_ms(0, &timeout_flag);

    for (int i = 0; i < 1000; i++) {
	verbose_log("Testing send from %p to %p, iteration %d\n",
		    src, dst, i);

	bool hello_done = false;
	bool hello_success = false;
	XorpTimer hello_timer = e.new_oneoff_after_ms(5,
						      callback(send_hello,
							       src,
							       &hello_success,
							       &hello_done));

	timeout.reschedule_after_ms(500);
	while (false == hello_done) {
	    e.run();
	}

	if (timeout_flag) {
	    verbose_log("Timed out waiting for xrl response.\n");
	    return 1;
	}

	if (false == hello_success) {
	    verbose_log("Xrl dispatched, but error reported.\n");
	    return 1;
	}
    }
    return 0;
}

static int
test_main(void)
{
    EventLoop e;

    FinderTcpMessenger* client = 0;

    IPv4 ipc_addr = if_get_preferred();
    DummyFinder finder(e, ipc_addr);

    add_commands(xrl_cmds);

    bool timeout_flag = false;
    XorpTimer timeout;

    /*************** Prepare to connect client to DummyFinder ****************/
    bool client_failed = false;
    XorpTimer connect_timer = e.new_oneoff_after_ms(
				1, callback(connect_client,
					    &e, &client, &client_failed));

    timeout = e.set_flag_after_ms(5000, &timeout_flag);
    
    while (client_failed == false && timeout_flag == false) {
	verbose_log("client %p, server connection %p\n",
		    client, finder.messenger());
	e.run();
	if (0 != client && 0 != finder.messenger())
	    break;
    }

    if (client_failed) {
	verbose_log("Client connect failed.");
	return 1;
    }
    if (timeout_flag) {
	verbose_log("Client connect timeout.");
	return 1;
    }

    timeout.unschedule();

    /******************* Get client to say hello to finder *******************/

    if (test_hellos(e, client, finder.messenger())) {
	delete client;
	return 1;
    }
    if (test_hellos(e, finder.messenger(), client)) {
	delete client;
	return 1;
    }
    
    delete client;

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
//
// Standard test program rubble.
//

/**
 * Print program info to output stream.
 * 
 * @param stream the output stream the print the program info to.
 */
static void
print_program_info(FILE *stream)
{
    fprintf(stream, "Name:          %s\n", program_name);
    fprintf(stream, "Description:   %s\n", program_description);
    fprintf(stream, "Version:       %s\n", program_version_id);
    fprintf(stream, "Date:          %s\n", program_date);
    fprintf(stream, "Copyright:     %s\n", program_copyright);
    fprintf(stream, "Return:        %s\n", program_return_value);
}

/**
 * Print program usage information to the stderr.
 * 
 * @param progname the name of the program.
 */
static void
usage(const char* progname)
{
    print_program_info(stderr);
    fprintf(stderr, "usage: %s [-v] [-h]\n", progname);
    fprintf(stderr, "       -h          : usage (this message)\n");
    fprintf(stderr, "       -v          : verbose output\n");
}

int
main(int argc, char * const argv[])
{
   int ret_value = 0;
    
    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);         // Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();
    
    int ch;
    while ((ch = getopt(argc, argv, "hv")) != -1) {
        switch (ch) {
        case 'v':
            set_verbose(true);
            break;
        case 'h':
        case '?':
        default:
            usage(argv[0]);
            xlog_stop();
            xlog_exit();
            if (ch == 'h')
                return (0);
            else
                return (1);
        }
    }
    argc -= optind;
    argv += optind;
    
    XorpUnexpectedHandler x(xorp_unexpected_handler);
    try {
	ret_value = test_main();
    } catch (...) {
        // Internal error
        xorp_print_standard_exceptions();
        ret_value = 2;
    }
   
    //
    // Gracefully stop and exit xlog
    //
    xlog_stop();
    xlog_exit();
    
    return (ret_value);
}
