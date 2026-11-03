#include <so/so_module_accesser.h>
#pragma force_active on

extern const float lbl_120_rodata_30;

extern "C" void fn_120_ECEC(soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000015)) {
        accesser->getControllerModule().setRumble(8, 0, false, 7);
    } else {
        accesser->getControllerModule().stopRumbleKind(8, 7);
    }
    if (accesser->getWorkManageModule().getFloat(0x11000015) <= lbl_120_rodata_30) {
        accesser->getControllerModule().stopRumbleKind(2, 7);
        accesser->getControllerModule().stopRumbleKind(4, 7);
        accesser->getControllerModule().stopRumbleKind(8, 7);
    }
}