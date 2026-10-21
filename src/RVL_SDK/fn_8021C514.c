#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u8 lbl_805A0C72;

void fn_8021C514(int arg0) {
    int var_r0;
    BOOL status = OSDisableInterrupts();
    var_r0 = arg0;
    if (arg0 == 0) {
        var_r0 = 0;
    }
    if ((unsigned)arg0 >= 0x7F) {
        var_r0 = 0x7F;
    }
    lbl_805A0C72 = var_r0;
    OSRestoreInterrupts(status);
}
