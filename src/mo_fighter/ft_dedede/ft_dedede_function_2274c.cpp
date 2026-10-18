#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_117_rodata_138, lbl_117_rodata_13C;
}

extern "C" void fn_117_2274C(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2) {
        if (accesser->getPostureModule().getLr() == lbl_117_rodata_138) {
            accesser->getModelModule().setNodeRotateY(4, lbl_117_rodata_13C);
        }
    }
}
