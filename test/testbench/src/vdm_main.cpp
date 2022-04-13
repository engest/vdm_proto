#include "testbench.h"
using namespace sc_core;
int sc_main(int argc, char * argv[]) {
    // Instance top
    testbench tb("tb");
    sc_core::sc_start();
    return 0;
}