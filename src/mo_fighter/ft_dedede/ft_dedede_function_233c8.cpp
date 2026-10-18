#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_117_rodata_148, lbl_117_rodata_14C;
}

extern "C" void fn_117_233C8(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2) {
        if (accesser->getPostureModule().getLr() == lbl_117_rodata_148) {
            accesser->getModelModule().setNodeRotateY(4, lbl_117_rodata_14C);
        }
    }
}
