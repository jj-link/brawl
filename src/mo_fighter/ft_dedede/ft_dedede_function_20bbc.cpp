#include <so/so_module_accesser.h>
#pragma force_active on

namespace {
struct DededeFighter {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" void fn_117_20BBC(DededeFighter* fighter) {
    fighter->accesser->getStatusModule().changeStatusForce(8, fighter->accesser);
}
