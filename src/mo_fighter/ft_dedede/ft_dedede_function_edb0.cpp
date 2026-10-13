#include <so/so_module_accesser.h>

extern "C" {
extern const float lbl_117_rodata_28[3];
extern const float lbl_117_rodata_34;
}

extern "C" void fn_117_EDB0(void*, soModuleAccesser* accesser, int status) {
    if (status == 0x12B || status == 0x12E || status == 0x12C) {
        if (accesser->getWorkManageModule().isFlag(0x22000010)) {
            accesser->getPostureModule().setLr(lbl_117_rodata_28[1]);
        } else {
            accesser->getPostureModule().setLr(lbl_117_rodata_34);
        }
    }
    accesser->getModelModule().clearNodeSRT(7);
}
