#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_118_F958(int frames, float value, soModuleAccesser* accesser) {
    accesser->getWorkManageModule().setFloat((float)frames, 0x11000000);
    accesser->getWorkManageModule().setFloat(value, 0x11000001);
    accesser->getWorkManageModule().onFlag(0x12000003);
}

extern const unsigned int lbl_118_rodata_68[2] = { 0x42652ee1, 0x4096cbe4 };
