/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "test_xrls_xif.hh"

bool
XrlTestXrlsV0p1Client::send_start_transmission(
	const char*	the_tgt,
	const StartTransmissionCB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/start_transmission");
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_start_transmission, cb));
}


/* Unmarshall start_transmission */
void
XrlTestXrlsV0p1Client::unmarshall_start_transmission(
	const XrlError&	e,
	XrlArgs*	a,
	StartTransmissionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestXrlsV0p1Client::send_end_transmission(
	const char*	the_tgt,
	const EndTransmissionCB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/end_transmission");
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_end_transmission, cb));
}


/* Unmarshall end_transmission */
void
XrlTestXrlsV0p1Client::unmarshall_end_transmission(
	const XrlError&	e,
	XrlArgs*	a,
	EndTransmissionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestXrlsV0p1Client::send_add_xrl0(
	const char*	the_tgt,
	const AddXrl0CB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/add_xrl0");
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_add_xrl0, cb));
}


/* Unmarshall add_xrl0 */
void
XrlTestXrlsV0p1Client::unmarshall_add_xrl0(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrl0CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestXrlsV0p1Client::send_add_xrl1(
	const char*	the_tgt,
	const string&	data1,
	const AddXrl1CB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/add_xrl1");
    x.args().add("data1", data1);
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_add_xrl1, cb));
}


/* Unmarshall add_xrl1 */
void
XrlTestXrlsV0p1Client::unmarshall_add_xrl1(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrl1CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestXrlsV0p1Client::send_add_xrl2(
	const char*	the_tgt,
	const string&	data1,
	const string&	data2,
	const AddXrl2CB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/add_xrl2");
    x.args().add("data1", data1);
    x.args().add("data2", data2);
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_add_xrl2, cb));
}


/* Unmarshall add_xrl2 */
void
XrlTestXrlsV0p1Client::unmarshall_add_xrl2(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrl2CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestXrlsV0p1Client::send_add_xrl9(
	const char*	the_tgt,
	const bool&	data1,
	const int32_t&	data2,
	const IPv4&	data3,
	const IPv4Net&	data4,
	const IPv6&	data5,
	const IPv6Net&	data6,
	const Mac&	data7,
	const string&	data8,
	const vector<uint8_t>&	data9,
	const AddXrl9CB&	cb
)
{
    Xrl x(the_tgt, "test_xrls/0.1/add_xrl9");
    x.args().add("data1", data1);
    x.args().add("data2", data2);
    x.args().add("data3", data3);
    x.args().add("data4", data4);
    x.args().add("data5", data5);
    x.args().add("data6", data6);
    x.args().add("data7", data7);
    x.args().add("data8", data8);
    x.args().add("data9", data9);
    return _sender->send(x, callback(this, &XrlTestXrlsV0p1Client::unmarshall_add_xrl9, cb));
}


/* Unmarshall add_xrl9 */
void
XrlTestXrlsV0p1Client::unmarshall_add_xrl9(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrl9CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
