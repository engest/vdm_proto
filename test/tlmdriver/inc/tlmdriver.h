#ifndef __VDM_DRV_H__
#define __VDM_DRV_H__

#include "systemc.h"
#include "tlm.h"
#include "simple_initiator_socket.h"

using namespace std;
using namespace sc_core;
using namespace tlm_utils;
using namespace tlm;
class tlmdriver : public sc_module
{
public:
    tlmdriver(sc_module_name name);
    simple_initiator_socket<tlmdriver> isocket;

private:
    void drive();
};
#endif