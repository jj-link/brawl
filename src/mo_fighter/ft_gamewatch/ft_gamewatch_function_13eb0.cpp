#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" {
extern const float lbl_107_rodata_B4;

void fn_107_13EB0(void*, soModuleAccesser* acc) {
    acc->getWorkManageModule().setFloat(lbl_107_rodata_B4, 0x11000000);
    acc->getWorkManageModule().offFlag(0x12000003);
}
}
