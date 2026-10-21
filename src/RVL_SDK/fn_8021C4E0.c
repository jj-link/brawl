#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u8 lbl_805A0C72;

u8 fn_8021C4E0(void) {
    u8 temp_r31;
    BOOL status = OSDisableInterrupts();

    temp_r31 = lbl_805A0C72;
    OSRestoreInterrupts(status);
    return temp_r31;
}
