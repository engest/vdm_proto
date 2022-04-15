#ifndef __VDM_TB_H__
#define __VDM_TB_H__

#include "systemc.h"
#include "tlm.h"

#include "vdm_proto.h"
#include "tlmdriver.h"

class testbench : public sc_module
{
public:
    vdm_proto device;
    tlmdriver driver;
    testbench(sc_module_name name);
    
};

#endif
