#include "tlmdriver.h"

tlmdriver::tlmdriver(sc_module_name name) {
    SC_HAS_PROCESS(tlmdriver);
    SC_THREAD(drive);
}
void tlmdriver::drive() {
    while (true)
    {
        //Create GP

        // Send GP

        // Wait a time
    }
    
}