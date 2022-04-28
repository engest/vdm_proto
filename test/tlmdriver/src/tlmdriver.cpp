#include "tlmdriver.h"

tlmdriver::tlmdriver(sc_module_name name) : isocket("isocket") {
    SC_HAS_PROCESS(tlmdriver);
    SC_THREAD(drive);
    cout << "Greetings from driver\n";
    gp = new tlm_generic_payload();
    gp_delay = sc_time(0, SC_NS);
}

void tlmdriver::start_of_simulation() {
}

void tlmdriver::drive() {
    while (true)
    {
        
        // unsigned char * data = new unsigned char[4];
        unsigned int write_data = 0xADC0FFEE;
        write32((unsigned char *)&write_data, 0xDEADBEEF);

        unsigned int read_data = 0x00000000;
        read32((unsigned char *)&read_data, 0xDEADBEEF);
        // Wait a time
        wait(10, SC_NS);
    }
}

tlm_response_status tlmdriver::read32(unsigned char * data, uint64_t address) {
        //Create GP
        gp->reset();
        gp->set_address(address);
        gp->set_data_length(4);
        gp->set_read();
        gp->set_data_ptr(data);
        gp->set_byte_enable_length(4);
        // Send GP
        isocket->b_transport(*gp, gp_delay);
    return TLM_OK_RESPONSE;
}

tlm_response_status tlmdriver::write32(unsigned char * data, uint64_t address) {
        //Create GP
        gp->reset();
        gp->set_address(address);
        gp->set_data_length(4);
        gp->set_write();
        gp->set_data_ptr(data);
        gp->set_byte_enable_length(4);
        // Send GP
        isocket->b_transport(*gp, gp_delay);
    return TLM_OK_RESPONSE;
}
