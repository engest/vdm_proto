#include "tlmdriver.h"

tlmdriver::tlmdriver(sc_module_name name) : isocket("isocket") {
    SC_HAS_PROCESS(tlmdriver);
    SC_THREAD(drive);
    cout << "Greatings from driver\n";
}

void tlmdriver::start_of_simulation() {
}

void tlmdriver::drive() {
    while (true)
    {
        //Create GP

        // Send GP

        cout << "Driving time:" << sc_time_stamp() << "\n";
        // Wait a time
        wait(10, SC_NS);
    }
    
}