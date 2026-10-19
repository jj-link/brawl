#include <so/so_module_accesser.h>
#pragma force_active on

struct PikachuStorageOwnerAccess {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" void* fn_98_1492C(PikachuStorageOwnerAccess* owner) {
    return reinterpret_cast<void*>(owner->accesser->getWorkManageModule().getInt(0x10000006));
}
