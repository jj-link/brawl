#include <so/so_module_accesser.h>

struct PikachuVortexEventOwner {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};

// Collision bit 1 becomes the transient work flag consumed by the status update.
extern "C" int fn_98_1B82C(PikachuVortexEventOwner* owner, unsigned int flags) {
    if (flags & 2) owner->accesser->getWorkManageModule().onFlag(0x12000005);
    return 0;
}

extern "C" void fn_98_1B9EC(soModuleAccesser*, int);
extern "C" void fn_98_1B904(soModuleAccesser*, int, unsigned int);

// Only the two defined modes change the effect handles; other values are inert.
extern "C" void fn_98_1B878(soModuleAccesser* accesser, int mode) {
    switch (mode) {
    case 0:
        fn_98_1B9EC(accesser, 0x10000006);
        fn_98_1B904(accesser, 0x10000005, 0xe80002);
        break;
    case 1:
        fn_98_1B9EC(accesser, 0x10000005);
        fn_98_1B904(accesser, 0x10000006, 0xe80001);
        break;
    }
}
