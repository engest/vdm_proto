#include "testbench.h"
#include "vdm_proto.h"
#include "tlmdriver.h"

testbench::testbench(sc_module_name name) {
    vdm_proto device("device");
    tlmdriver drive("driver");

    drive.isocket.bind(device.tsocket);
}
