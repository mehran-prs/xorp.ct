/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/mld6igmp_client_xif.cc,v 1.2 2003/01/10 00:30:28 hodson Exp $"

#include "mld6igmp_client_xif.hh"

bool
XrlMld6igmpClientV0p1Client::send_add_membership4(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv4&	source, 
	const IPv4&	group, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "mld6igmp_client/0.1/add_membership4");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    x.args().add("source", source);
    x.args().add("group", group);
    return _router->send(x, callback(this, &XrlMld6igmpClientV0p1Client::unmarshall0, cb));
}


/* Unmarshall add_membership4 */
void
XrlMld6igmpClientV0p1Client::unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    bool fail;
    string reason;
    try {
	a->get("fail", fail);
	a->get("reason", reason);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &fail, &reason);
}

bool
XrlMld6igmpClientV0p1Client::send_add_membership6(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv6&	source, 
	const IPv6&	group, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "mld6igmp_client/0.1/add_membership6");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    x.args().add("source", source);
    x.args().add("group", group);
    return _router->send(x, callback(this, &XrlMld6igmpClientV0p1Client::unmarshall1, cb));
}


/* Unmarshall add_membership6 */
void
XrlMld6igmpClientV0p1Client::unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    bool fail;
    string reason;
    try {
	a->get("fail", fail);
	a->get("reason", reason);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &fail, &reason);
}

bool
XrlMld6igmpClientV0p1Client::send_delete_membership4(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv4&	source, 
	const IPv4&	group, 
	const CB2&	cb
)
{
    Xrl x(the_tgt, "mld6igmp_client/0.1/delete_membership4");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    x.args().add("source", source);
    x.args().add("group", group);
    return _router->send(x, callback(this, &XrlMld6igmpClientV0p1Client::unmarshall2, cb));
}


/* Unmarshall delete_membership4 */
void
XrlMld6igmpClientV0p1Client::unmarshall2(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB2		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    bool fail;
    string reason;
    try {
	a->get("fail", fail);
	a->get("reason", reason);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &fail, &reason);
}

bool
XrlMld6igmpClientV0p1Client::send_delete_membership6(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const IPv6&	source, 
	const IPv6&	group, 
	const CB3&	cb
)
{
    Xrl x(the_tgt, "mld6igmp_client/0.1/delete_membership6");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    x.args().add("source", source);
    x.args().add("group", group);
    return _router->send(x, callback(this, &XrlMld6igmpClientV0p1Client::unmarshall3, cb));
}


/* Unmarshall delete_membership6 */
void
XrlMld6igmpClientV0p1Client::unmarshall3(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB3		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != 2)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    bool fail;
    string reason;
    try {
	a->get("fail", fail);
	a->get("reason", reason);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &fail, &reason);
}
