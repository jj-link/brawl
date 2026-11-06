#include <revolution/OS/OSInterrupt.h>
#include <revolution/SI/SIHardware.h>
#pragma force_active on

extern u32 lbl_80474EB0[];

u32 fn_801E6A4C(s32 chan) {
    BOOL enabled;
    u32 sr;

    enabled = OSDisableInterrupts();
    sr = SI_HW_REGS[SI_SISR];
    sr = sr >> ((3 - chan) * 8);
    if (sr & SI_SISR_NOREP3) {
        if (!(lbl_80474EB0[chan] & 0x80)) {
            lbl_80474EB0[chan] = 8;
        }
    }
    OSRestoreInterrupts(enabled);
    return sr;
}
