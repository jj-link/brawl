#include <so/so_module_accesser.h>

struct PikachuVortexCleanupOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
extern "C" void fn_98_1B9EC(soModuleAccesser*, int);

extern "C" void fn_98_1B634(PikachuVortexCleanupOwner* owner) {
    soModuleAccesser* accesser = owner->accesser;
    fn_98_1B9EC(accesser, 0x10000005);
    fn_98_1B9EC(accesser, 0x10000006);
    accesser->getCameraModule().setWhole(false);
}
