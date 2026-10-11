#include <so/so_module_accesser.h>

struct PikachuSecondaryStorageOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
void fn_98_17CC8(PikachuSecondaryStorageOwner* owner, void* storage) {
    owner->accesser->getWorkManageModule().setInt(reinterpret_cast<int>(storage), 0x10000006);
}

void* fn_98_17CEC(PikachuSecondaryStorageOwner* owner) {
    return reinterpret_cast<void*>(owner->accesser->getWorkManageModule().getInt(0x10000006));
}
}
