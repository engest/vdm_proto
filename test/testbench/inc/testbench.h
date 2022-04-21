/**
 * @file testbench.h
 * @author Stephen Engelman
 * @brief Testbench top for the vdm_proto and tlmdriver
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __VDM_TB_H__
#define __VDM_TB_H__

#include "systemc.h"
#include "tlm.h"

#include "vdm_proto.h"
#include "tlmdriver.h"

/**
 * @brief Testbench module
 * 
 * The top of the "design."
 * 
 */
class testbench : public sc_module
{
public:
    /**
     * @brief Instance of the device under test vdm_proto
     * 
     */
    vdm_proto device;

    /**
     * @brief Instance of the testing module
     * 
     */
    tlmdriver driver;

    /**
     * @brief Construct a new testbench object
     * 
     * @param name SystemC Name string
     */
    testbench(sc_module_name name);
    
};

#endif
