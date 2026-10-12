#include <so/so_module_accesser.h>

extern "C" const float lbl_117_rodata_50;

extern "C" void fn_117_FD3C(void*, soModuleAccesser* accesser, int duration, bool checkLoop) {
    bool motionLooped = false;
    if (checkLoop && accesser->getMotionModule().isLooped())
        motionLooped = true;

    if (lbl_117_rodata_50 == accesser->getMotionModule().getFrame() || motionLooped) {
        if (accesser->getWorkManageModule().isFlag(0x22000012)) {
            accesser->getControllerModule().stopRumbleKind(4, 7);
            accesser->getControllerModule().setRumble(4, duration, false, 7);
        } else {
            accesser->getControllerModule().stopRumbleKind(2, 7);
            accesser->getControllerModule().setRumble(2, duration, false, 7);
        }
    } else if (accesser->getWorkManageModule().isFlag(0x22000014)) {
        int frame = static_cast<int>(accesser->getMotionModule().getFrame());
        if (frame < duration) {
            frame = duration - frame;
            accesser->getControllerModule().stopRumbleKind(2, 7);
            accesser->getControllerModule().setRumble(4, frame, false, 7);
        }
        accesser->getWorkManageModule().offFlag(0x22000014);
    }
}
