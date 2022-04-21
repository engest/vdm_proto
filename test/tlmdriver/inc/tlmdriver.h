/**
 * @file tlmdriver.h
 * @author Stephen Engelman
 * @brief TLM2 initiator driver module
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __VDM_DRV_H__
#define __VDM_DRV_H__

#include "systemc.h"
#include "tlm.h"
#include "simple_initiator_socket.h"

using namespace std;
using namespace sc_core;
using namespace tlm_utils;
using namespace tlm;

/**
 * @brief TLM2 initiator driver module class
 * 
 * This module is intended to be used to initiate transactions to the device under test, the vdm_proto module.
 * 
 */
class tlmdriver : public sc_module
{
public:

    /**
     * @brief Construct a new tlmdriver object
     * 
     * @param name SystemC Name string
     */
    tlmdriver(sc_module_name name);

    /**
     * @brief TLM2 simple initiator socket
     * 
     */
    simple_initiator_socket<tlmdriver> isocket;

    /**
     * @brief A SystemC event used for triggering an action
     * 
     * This is currently not used.
     * 
     */
    sc_event trigger;

    /**
     * @brief Callback from sc_module
     * 
     * This is inherited from sc_module class and is a callback for the start of actual simulation running.
     */
    void start_of_simulation();

    /**
     * @brief An SC_THREAD function
     * 
     * This is used as an SC_THREAD. It will be the main thread of initiating transactions and consuming time.
     */
    void drive();
};
#endif