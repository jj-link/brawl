#include <so/so_module_accesser.h>

struct PikachuWorkVectorOwner {
    char reserved[0x60];
    soModuleAccesser* accesser;
};
struct PikachuWorkVector {
    float x;
    float y;
    float z;
};

extern "C" void fn_98_17D58(PikachuWorkVector* result, PikachuWorkVectorOwner* owner) {
    soWorkManageModule* work = &owner->accesser->getWorkManageModule();
    result->x = work->getFloat(0x11000001);
    result->y = work->getFloat(0x11000002);
    result->z = work->getFloat(0x11000003);
}
