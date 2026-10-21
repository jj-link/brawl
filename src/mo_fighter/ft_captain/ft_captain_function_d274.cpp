#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_100_data_6294[], lbl_100_data_16D4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
struct SpeedView {
    unsigned char pad[0x10];
    float x;
    unsigned char pad2[8];
    float y;
};
}

extern "C" void fn_100_D274(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000000) == 0) {
        SpeedView* view = reinterpret_cast<SpeedView*>(__dynamic_cast(
            accesser->getKineticModule().getEnergy(1), 0,
            lbl_100_data_6294, lbl_100_data_16D4, 1));
        float a = soValueAccesser::getConstantFloat(accesser, 0xfa6, 0);
        float b = soValueAccesser::getConstantFloat(accesser, 0xfa7, 0);
        view->x = -a;
        view->y = b;
    }
}
