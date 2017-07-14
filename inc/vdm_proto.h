#include "systemc.h"
#include "simple_target_socket.h"

using namespace sc_core;
using namespace tlm_utils;

class vdm_proto : public sc_module
{
    public:
    vdm_proto(sc_module_name name);

};