#include "vdm_proto.h"

vdm_proto::vdm_proto(sc_module_name name) : sc_module(name)
                                          , tsocket("tsocket")
{
    tsocket.register_b_transport(this, &vdm_proto::b_transport);
    cout << "Greatings from vdm_proto\n";
}

void vdm_proto::b_transport(tlm_generic_payload & trans, sc_time & delay) {
    if (trans.is_read()) { // READ
        cout << "VDM received READ transation";
    } else { // WRITE
        cout << "VDM received WRITE transation";
    }
}