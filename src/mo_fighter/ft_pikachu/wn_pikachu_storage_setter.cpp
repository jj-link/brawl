#include <so/so_module_accesser.h>

struct PikachuStorageSetterOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" void fn_98_17D10(PikachuStorageSetterOwner* owner, void* storage) {
    owner->accesser->getWorkManageModule().setInt(reinterpret_cast<int>(storage), 0x10000005);
}
