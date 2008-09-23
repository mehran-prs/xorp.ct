// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2008 XORP, Inc.
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

// $XORP: xorp/libxipc/xrl.hh,v 1.22 2008/09/23 08:02:40 abittau Exp $

#ifndef __LIBXIPC_XRL_HH__
#define __LIBXIPC_XRL_HH__

#include <string>

#include "libxorp/exceptions.hh"
#include "xrl_atom.hh"
#include "xrl_args.hh"
#include "xrl_tokens.hh"

struct FinderDBEntry;

/**
 * XORP IPC request.
 */
class Xrl {
public:
    /**
     * Construct an Xrl.
     */
    Xrl(const string&	protocol,
	const string&	protocol_target,
	const string&	command,
	const XrlArgs&	args)
	: _protocol(protocol), _target(protocol_target), _command(command),
	  _args(args), _sna_atom(NULL), _packed_bytes(0), _argp(&_args),
	  _to_finder(-1), _resolved(NULL)
    {}

    /**
     * Construct an Xrl (with implicit finder protocol).
     */
    Xrl(const string&	target,
	const string&	command,
	const XrlArgs&	args)
	: _protocol(_finder_protocol), _target(target), _command(command),
	  _args(args), _sna_atom(NULL), _packed_bytes(0), _argp(&_args),
	  _to_finder(-1), _resolved(NULL)
    {}

    /**
     * Construct an Xrl that does not have an argument list.
     */
    Xrl(const string& protocol,
	const string& protocol_target,
	const string& command)
	: _protocol(protocol), _target(protocol_target), _command(command),
	  _sna_atom(NULL), _packed_bytes(0), _argp(&_args), _to_finder(-1),
	  _resolved(NULL)
    {}

    /**
     * Construct an Xrl that does not have an argument list.
     */
    Xrl(const string& target,
	const string& command)
	: _protocol(_finder_protocol), _target(target), _command(command),
	  _sna_atom(NULL), _packed_bytes(0), _argp(&_args), _to_finder(-1),
	  _resolved(NULL)
    {}

    /**
     * Construct an Xrl object from the string representation of Xrl.
     */
    Xrl(const char* xrl_c_str) throw (InvalidString);

    Xrl() : _sna_atom(0), _packed_bytes(0), _argp(&_args), _to_finder(-1),
            _resolved(NULL) {}
    ~Xrl();

    /**
     * Render Xrl as a string
     */
    string str() const;

    /**
     * @return the protocol associated with XRL.
     */
    const string& protocol() const		{ return _protocol; }

    /**
     * @return the name of the XRL target entity.
     */
    const string& target() const		{ return _target; }

    /**
     * @return string representation of Xrl without arguments.
     */
    const string& string_no_args() const;

    /**
     * @return the name of the command
     */
    const string& command() const		{ return _command; }

    /**
     * Retrieve list of arguments associated with the XRL.
     */
    XrlArgs& args()				{ return *_argp; }

    /**
     * Retrieve list of arguments associated with the XRL.
     */
    const XrlArgs& args() const			{ return *_argp; }

    /**
     * Test the equivalence of two XRL's.
     *
     * @return true if the XRL's are equivalent.
     */
    bool operator==(const Xrl& x) const;

    /**
     * @return true if Xrl is resolved, ie protocol == finder.
     */
    bool is_resolved() const;

    /**
     * Get number of bytes needed to pack XRL into a serialized byte form.
     */
    size_t packed_bytes() const;

    /**
     * Pack XRL into a byte array.  The size of the byte
     * array should be larger or equal to the value returned by
     * packed_bytes().
     *
     * @param buffer buffer to receive data.
     * @param buffer_bytes size of buffer.
     * @return size of packed data on success, 0 on failure.
     */
    size_t pack(uint8_t* buffer, size_t buffer_bytes) const;

    /**
     * Unpack XRL from serialized byte array.
     *
     * @param buffer to read data from.
     * @param buffer_bytes size of buffer.  The size should exactly match
     *        number of bytes of packed data, ie packed_bytes() value
     *        used when packing.
     * @return number of bytes turned into atoms on success, 0 on failure.
     */
    size_t unpack(const uint8_t* buffer, size_t buffer_bytes);

    void set_args(const Xrl& x) const;

    size_t fill(const uint8_t* buffer, size_t buffer_bytes);

    static size_t unpack_command(string& cmd, const uint8_t* in, size_t len);

    bool to_finder() const;

    const FinderDBEntry* resolved() const { return _resolved; }
    void set_resolved(const FinderDBEntry* r) const { _resolved = r; };

    void set_target(const char* target);

private:
    const char* parse_xrl_path(const char* xrl_path);
    void        clear_cache();

private:
    // if protocol != finder, target = protocol params
    string		_protocol;
    string		_target;
    string		_command;

    // XXX we got a const problem.  Factor out all cached stuff into a struct
    // and make that mutable.
    mutable XrlArgs		    _args; // XXX packed_bytes() and pack()
    mutable string		    _string_no_args;
    mutable XrlAtom*		    _sna_atom;
    mutable size_t		    _packed_bytes;
    mutable XrlArgs*		    _argp; // XXX shouldn't be mutable
    mutable int			    _to_finder;
    mutable const FinderDBEntry*    _resolved; // XXX ditto

    static const string _finder_protocol;
};

typedef Xrl XrlTemplate;

// ----------------------------------------------------------------------------
// Inline methods

inline const string&
Xrl::string_no_args() const
{
    if (!_string_no_args.size())
	_string_no_args =  _protocol 
			 + string(XrlToken::PROTO_TGT_SEP) 
			 + _target 
			 + string(XrlToken::TGT_CMD_SEP)
			 + _command;

    return _string_no_args;
}

#endif // __LIBXIPC_XRL_HH__
