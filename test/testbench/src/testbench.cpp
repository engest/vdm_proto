#include "testbench.h"

testbench::testbench(sc_module_name name) : device("device")
                                           ,driver("driver")
{
    cout << "Greetings from testbench\n";
    driver.isocket(device.tsocket);
    cout << "Post bind\n";
}
