#include <revolution/SI/SIHardware.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u32 lbl_80474E98[];

u32 fn_801E6B44(u32 arg0) {
    u32 r8, r7, r5, result;
    if (arg0 == 0)
        return lbl_80474E98[1];
    {
        u32 s = OSDisableInterrupts();
        arg0 >>= 24;
        r8 = (arg0 >> 4) & 0xF;
        r7 = r8 | 0x3FFFFF0;
        arg0 &= r7;
        r5 = lbl_80474E98[1] & ~r8;
        result = r5 | arg0;
        lbl_80474E98[1] = result;
        SI_HW_REGS[SI_SISR] = 0x80000000;
        SI_HW_REGS[SI_SIPOLL] = result;
        OSRestoreInterrupts(s);
        return result;
    }
}
