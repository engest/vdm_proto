/**
 * @file vdm_proto.h
 * @author Stephen Engelman
 * @brief Virtual Device Model Prototype header
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __VDM_PROTO_H__
#define __VDM_PROTO_H__

#include "systemc.h"
#include "simple_target_socket.h"
#include "simple_initiator_socket.h"

using namespace std;
using namespace sc_core;
using namespace tlm_utils;
using namespace tlm;

/**
 * @brief Virtual Device Model Prototype
 * 
 */
class vdm_proto : public sc_module
{
public:
    /**
     * @brief Construct a new vdm proto object
     * 
     * @param name SystemC Name string
     */
    vdm_proto(sc_module_name name);

    /**
     * @brief TLM2 target callback to handle blocking transactions 
     * 
     * @param trans Transaction object 
     * @param delay Annotated delay for modeling purposes
     */
    void b_transport(tlm_generic_payload & trans, sc_time & delay);

    /**
     * @brief TLM2 simple target socket
     * 
     * Socket for receiving read/write bus transactions from CPU or other initiating module
     */
    simple_target_socket<vdm_proto> tsocket;

};
#endif