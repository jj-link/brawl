#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern float lbl_120_rodata_18;
}

extern "C" void fn_120_DF74(void*, soModuleAccesser* accesser) {
    float value = accesser->getWorkManageModule().getFloat(0x21000004);
    float speed = value - soValueAccesser::getConstantFloat(accesser, 0xfba, 0);
    if (speed < lbl_120_rodata_18) {
        speed = lbl_120_rodata_18;
    }
    accesser->getWorkManageModule().setFloat(speed, 0x21000004);
}
