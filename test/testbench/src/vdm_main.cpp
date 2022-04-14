#include "testbench.h"
using namespace sc_core;
int sc_main(int argc, char * argv[]) {
    // Instance top
    testbench tb("tb");
    cout << "Pre sc_start()\n";
    sc_core::sc_start();
    cout << "Post sc_start()\n";
    return 0;
}