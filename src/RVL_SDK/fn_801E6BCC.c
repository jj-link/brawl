#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u32 lbl_80474E98[];

u32 fn_801E6BCC(u32 arg0) {
    u32 mask, r5, result, s;

    if (arg0 == 0)
        return lbl_80474E98[1];
    s = OSDisableInterrupts();
    mask = (arg0 >> 24) & 0xF0;
    r5 = lbl_80474E98[1];
    result = r5 & ~mask;
    *(u32 *)0xCD006430 = result;
    lbl_80474E98[1] = result;
    OSRestoreInterrupts(s);
    return result;
}
