#include "vdm_proto.h"

vdm_proto::vdm_proto(sc_module_name name) : sc_module(name)
                                          , tsocket("tsocket")
{
    tsocket.register_b_transport(this, &vdm_proto::b_transport);
    cout << "Greatings from vdm_proto\n";
}

void vdm_proto::b_transport(tlm_generic_payload & trans, sc_time & delay) {
    if (trans.is_read()) { // READ
        cout << "VDM received READ transation at " << sc_time_stamp() << "\n";
    } else { // WRITE
        cout << "VDM received WRITE transation at " << sc_time_stamp() << "\n";
        cout << "    address=" << hex << trans.get_address() << "\n";
        cout << "    data:\n";
        unsigned char * data = trans.get_data_ptr();
        for (int i = 0; i < 4; i++) {
            cout << "         [" << i << "]=" << (unsigned int)data[i] << "\n"; 
        }
    }
}