#ifndef __VDM_TB_H__
#define __VDM_TB_H__

#include "systemc.h"
#include "tlm.h"

class testbench : public sc_module
{
public:
    testbench(sc_module_name name);
    
};

#endif
