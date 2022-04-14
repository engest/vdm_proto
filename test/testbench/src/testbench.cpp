#include "testbench.h"
#include "vdm_proto.h"
#include "tlmdriver.h"

testbench::testbench(sc_module_name name) {
    vdm_proto device("device");
    tlmdriver driver("driver");
    cout << "Greetings from testbench\n";
    //driver.isocket(device.tsocket);
    cout << "Post bind\n";
}
