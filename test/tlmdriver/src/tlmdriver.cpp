#include "tlmdriver.h"

tlmdriver::tlmdriver(sc_module_name name) : isocket("isocket") {
    SC_HAS_PROCESS(tlmdriver);
    SC_THREAD(drive);
    cout << "Greatings from driver\n";
    gp = new tlm_generic_payload();
}

void tlmdriver::start_of_simulation() {
}

void tlmdriver::drive() {
    sc_time delay = sc_time(30, SC_NS);
    while (true)
    {
        //Create GP
        gp->reset();
        gp->set_address(0xBADBECCA);
        gp->set_data_length(4);
        gp->set_write();
        unsigned char * data = new unsigned char[4];
        for (int i = 0; i < 4; i++) {
            data[i] = i+1;
        }
        gp->set_data_ptr(data);
        gp->set_byte_enable_length(4);
        // Send GP
        isocket->b_transport(*gp, delay);
        delete[] data;
        cout << "Driving time:" << sc_time_stamp() << "\n";
        // Wait a time
        wait(10, SC_NS);
    }
    
}