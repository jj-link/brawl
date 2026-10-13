#include <so/so_module_accesser.h>

namespace {
struct DededeStatusObject {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
}

extern "C" int fn_117_208E8(DededeStatusObject* object) {
    soModuleAccesser* accesser = object->accesser;
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2) {
        return 0;
    }
    if (object->accesser->getWorkManageModule().isFlag(0x22000005)) {
        return 0;
    }
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0:
    case 1:
    case 7:
    case 8:
        return 0;
    default:
        return 1;
    }
}
