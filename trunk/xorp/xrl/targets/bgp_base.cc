/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/bgp_base.cc,v 1.4 2003/01/19 00:59:27 mjh Exp $"


#include "bgp_base.hh"

const XrlCmdError
XrlBgpTargetBase::handle_common_0_1_get_target_name(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling common/0.1/get_target_name", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string name; 
    try {
	XrlCmdError e = common_0_1_get_target_name(
	    name);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_target_name failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("name", name);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_common_0_1_get_version(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling common/0.1/get_version", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    string version; 
    try {
	XrlCmdError e = common_0_1_get_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for common/0.1/get_version failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_bgp_version(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling bgp/0.2/get_bgp_version", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t version; 
    try {
	XrlCmdError e = bgp_0_2_get_bgp_version(
	    version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_bgp_version failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("version", version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_local_config(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%u != 2) handling bgp/0.2/local_config", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_local_config(
	    xrl.const_args().get_uint32("as"), 
	    xrl.const_args().get_ipv4("id"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/local_config failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_local_as(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%u != 1) handling bgp/0.2/set_local_as", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_local_as(
	    xrl.const_args().get_uint32("as"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_local_as failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_local_as(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling bgp/0.2/get_local_as", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t as; 
    try {
	XrlCmdError e = bgp_0_2_get_local_as(
	    as);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_local_as failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("as", as);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_bgpid(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%u != 1) handling bgp/0.2/set_bgpid", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_bgpid(
	    xrl.const_args().get_ipv4("id"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_bgpid failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_bgpid(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling bgp/0.2/get_bgpid", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    IPv4 id; 
    try {
	XrlCmdError e = bgp_0_2_get_bgpid(
	    id);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_bgpid failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("id", id);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_add_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 7) { 
	XLOG_ERROR("Wrong number of arguments (%u != 7) handling bgp/0.2/add_peer", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_add_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_uint32("as"), 
	    xrl.const_args().get_ipv4("next_hop"), 
	    xrl.const_args().get_uint32("holdtime"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/add_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_delete_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%u != 5) handling bgp/0.2/delete_peer", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_delete_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_uint32("as"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/delete_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_enable_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/enable_peer", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_enable_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/enable_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_disable_peer(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/disable_peer", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_disable_peer(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/disable_peer failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_peer_state(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%u != 5) handling bgp/0.2/set_peer_state", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_peer_state(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_bool("toggle"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_peer_state failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_list_start(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling bgp/0.2/get_peer_list_start", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t token; 
    bool more; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_list_start(
	    token, 
	    more);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_list_start failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("token", token);
	args->add("more", more);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_list_next(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%u != 1) handling bgp/0.2/get_peer_list_next", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    IPv4 local_ip; 
    uint32_t local_port; 
    IPv4 peer_ip; 
    uint32_t peer_port; 
    bool more; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_list_next(
	    xrl.const_args().get_uint32("token"), 
	    local_ip, 
	    local_port, 
	    peer_ip, 
	    peer_port, 
	    more);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_list_next failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("local_ip", local_ip);
	args->add("local_port", local_port);
	args->add("peer_ip", peer_ip);
	args->add("peer_port", peer_port);
	args->add("more", more);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_id(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_id", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    IPv4 peer_id; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_id(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    peer_id);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_id failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("peer_id", peer_id);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_status(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_status", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t peer_state; 
    uint32_t admin_status; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_status(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    peer_state, 
	    admin_status);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_status failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("peer_state", peer_state);
	args->add("admin_status", admin_status);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_negotiated_version(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_negotiated_version", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    int32_t neg_version; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_negotiated_version(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    neg_version);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_negotiated_version failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("neg_version", neg_version);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_as(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_as", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t peer_as; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_as(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    peer_as);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_as failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("peer_as", peer_as);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_msg_stats(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_msg_stats", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t in_updates; 
    uint32_t out_updates; 
    uint32_t in_msgs; 
    uint32_t out_msgs; 
    uint32_t last_error; 
    uint32_t in_update_elapsed; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_msg_stats(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    in_updates, 
	    out_updates, 
	    in_msgs, 
	    out_msgs, 
	    last_error, 
	    in_update_elapsed);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_msg_stats failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("in_updates", in_updates);
	args->add("out_updates", out_updates);
	args->add("in_msgs", in_msgs);
	args->add("out_msgs", out_msgs);
	args->add("last_error", last_error);
	args->add("in_update_elapsed", in_update_elapsed);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_established_stats(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_established_stats", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t transitions; 
    uint32_t established_time; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_established_stats(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    transitions, 
	    established_time);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_established_stats failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("transitions", transitions);
	args->add("established_time", established_time);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_get_peer_timer_config(const Xrl& xrl, XrlArgs* args)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/get_peer_timer_config", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    if (args == 0) {
	XLOG_FATAL("Return list empty");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    uint32_t retry_interval; 
    uint32_t hold_time; 
    uint32_t keep_alive; 
    uint32_t hold_time_conf; 
    uint32_t keep_alive_conf; 
    uint32_t min_as_orginiation_interval; 
    uint32_t min_route_adv_interval; 
    try {
	XrlCmdError e = bgp_0_2_get_peer_timer_config(
	    xrl.const_args().get_ipv4("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_ipv4("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    retry_interval, 
	    hold_time, 
	    keep_alive, 
	    hold_time_conf, 
	    keep_alive_conf, 
	    min_as_orginiation_interval, 
	    min_route_adv_interval);
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/get_peer_timer_config failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }

    /* Marshall return values */
    try {
	args->add("retry_interval", retry_interval);
	args->add("hold_time", hold_time);
	args->add("keep_alive", keep_alive);
	args->add("hold_time_conf", hold_time_conf);
	args->add("keep_alive_conf", keep_alive_conf);
	args->add("min_as_orginiation_interval", min_as_orginiation_interval);
	args->add("min_route_adv_interval", min_route_adv_interval);
    } catch (const XrlArgs::XrlAtomFound& ) {
	XLOG_FATAL("Duplicate atom name"); /* XXX Should never happen */
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_register_rib(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%u != 1) handling bgp/0.2/register_rib", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_register_rib(
	    xrl.const_args().get_string("name"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/register_rib failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_add_route(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling bgp/0.2/add_route", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_add_route(
	    xrl.const_args().get_int32("origin"), 
	    xrl.const_args().get_int32("asnum"), 
	    xrl.const_args().get_ipv4("next_hop"), 
	    xrl.const_args().get_ipv4net("nlri"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/add_route failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_delete_route(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 1) { 
	XLOG_ERROR("Wrong number of arguments (%u != 1) handling bgp/0.2/delete_route", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_delete_route(
	    xrl.const_args().get_ipv4net("nlri"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/delete_route failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_terminate(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 0) { 
	XLOG_ERROR("Wrong number of arguments (%u != 0) handling bgp/0.2/terminate", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_terminate();
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/terminate failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_bgp_0_2_set_parameter(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 5) { 
	XLOG_ERROR("Wrong number of arguments (%u != 5) handling bgp/0.2/set_parameter", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = bgp_0_2_set_parameter(
	    xrl.const_args().get_string("local_ip"), 
	    xrl.const_args().get_uint32("local_port"), 
	    xrl.const_args().get_string("peer_ip"), 
	    xrl.const_args().get_uint32("peer_port"), 
	    xrl.const_args().get_string("parameter"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for bgp/0.2/set_parameter failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_changed4(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling rib_client/0.1/route_info_changed4", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed4(
	    xrl.const_args().get_ipv4("addr"), 
	    xrl.const_args().get_uint32("prefix_len"), 
	    xrl.const_args().get_ipv4("nexthop"), 
	    xrl.const_args().get_uint32("metric"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_changed4 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_changed6(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 4) { 
	XLOG_ERROR("Wrong number of arguments (%u != 4) handling rib_client/0.1/route_info_changed6", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed6(
	    xrl.const_args().get_ipv6("addr"), 
	    xrl.const_args().get_uint32("prefix_len"), 
	    xrl.const_args().get_ipv6("nexthop"), 
	    xrl.const_args().get_uint32("metric"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_changed6 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_invalid4(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%u != 2) handling rib_client/0.1/route_info_invalid4", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid4(
	    xrl.const_args().get_ipv4("addr"), 
	    xrl.const_args().get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_invalid4 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlBgpTargetBase::handle_rib_client_0_1_route_info_invalid6(const Xrl& xrl, XrlArgs* /* args */)
{
    if (xrl.const_args().size() != 2) { 
	XLOG_ERROR("Wrong number of arguments (%u != 2) handling rib_client/0.1/route_info_invalid6", (uint32_t)xrl.const_args().size());
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid6(
	    xrl.const_args().get_ipv6("addr"), 
	    xrl.const_args().get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for rib_client/0.1/route_info_invalid6 failed: %s \"%s\"",
            		 e.str().c_str(), e.note().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

