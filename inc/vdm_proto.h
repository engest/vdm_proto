#ifndef __VDM_PROTO_H__
#define __VDM_PROTO_H__

#include "systemc.h"
#include "simple_target_socket.h"
#include "simple_initiator_socket.h"

using namespace std;
using namespace sc_core;
using namespace tlm_utils;
using namespace tlm;

class vdm_proto : public sc_module
{
public:
    vdm_proto(sc_module_name name);
    void b_transport(tlm_generic_payload & trans, sc_time & delay);

    simple_target_socket<vdm_proto> tsocket;

};
#endif