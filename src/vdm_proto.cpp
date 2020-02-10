#include "vdm_proto.h"

vdm_proto::vdm_proto(sc_module_name name) : sc_module(name)
                                          , tsocket("tsocket")
                                          , isocket("tsocket") {
    tsocket.register_b_transport(this, &vdm_proto::b_transport);
}

void vdm_proto::b_transport(tlm_generic_payload & trans, sc_time & delay) {
    while (true) {
        wait(start);
        if (trans.is_read()) { // READ

        } else { // WRITE
            for (int i = 0; i < trans.get_data_length(); i++) {
                data_store.clear();
                data_store.resize(trans.get_data_length());
                data_store.push_back((trans.get_data_ptr())[i]);
            }
        }
    }
}

void decode_data(unsigned char * data, unsigned int len) {
    unsigned int header_len = 0;
    unsigned int footer_len = 0;
    unsigned int payload_len = 0;
    if (len > 0)
        header_len = data[0];
    unsigned char header[header_len];
}