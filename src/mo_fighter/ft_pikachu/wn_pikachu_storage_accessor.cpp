#include <so/so_module_accesser.h>

struct PikachuStorageOwnerAccess {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" void* fn_98_17D34(PikachuStorageOwnerAccess* owner) {
    return reinterpret_cast<void*>(owner->accesser->getWorkManageModule().getInt(0x10000005));
}
