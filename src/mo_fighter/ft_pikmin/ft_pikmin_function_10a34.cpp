#include <so/so_module_accesser.h>
#pragma force_active on
extern const float lbl_113_rodata_20;
extern const float lbl_113_rodata_24;
extern "C" void fn_113_10A34(unsigned char* flags, soModuleAccesser* accesser) {
    int status = accesser->getStatusModule().getStatusKind();
    int previous = accesser->getStatusModule().getPrevStatusKind(0);
    float frame = accesser->getMotionModule().getFrame();
    switch (status) {
    case 0x0B:
        *flags |= 2;
        if (previous != 0x0C && frame <= lbl_113_rodata_24) *flags |= 4;
        break;
    case 0x0C:
        if (previous != 0x0C && frame <= lbl_113_rodata_24) *flags |= 4;
        break;
    case 0x7A: case 0xC4:
        if (frame <= lbl_113_rodata_24) *flags |= 4;
        break;
    case 0x45: case 0x46:
        if (accesser->getWorkManageModule().isFlag(0x22000018) &&
            accesser->getWorkManageModule().getInt(0x10000038) > 0) *flags |= 8;
        break;
    case 8: *flags |= 0x42; break;
    case 5: case 0x26: case 0x7C: case 0x7D:
        *flags |= 0x40; break;
    case 0x1F: case 0x20: case 0x61: case 0x90: case 0x91:
        if (frame <= lbl_113_rodata_24) *flags |= 1;
        *flags |= 0x42; break;
    case 1: case 4: *flags |= 2; break;
    case 3:
        if (frame <= lbl_113_rodata_24) *flags |= 1;
        *flags |= 2; break;
    case 0: case 0x2C: case 0x2F: case 0x32:
        *flags |= 0x40; break;
    }
    if (accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0) == 1 &&
        accesser->getGroundModule().getTouchLineRate(static_cast<grCollStatus::TouchMask>(8), 0) < lbl_113_rodata_20) {
        *flags |= 0x10;
    }
    if (!accesser->getGroundModule().isPassableCheck(0)) *flags |= 0x20;
}