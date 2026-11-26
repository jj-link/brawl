#include <revolution/OS/OSInterrupt.h>
#include <revolution/SI/SIHardware.h>
#include <types.h>
#pragma force_active on

extern u32 lbl_804DE4E0[4];

s32 fn_801E667C(s32 arg0) {
    u32 *p;
    BOOL enabled;
    BOOL rc;
    u32 reg;

    enabled = OSDisableInterrupts();
    reg = SI_HW_REGS[SI_SICOMSCR];
    rc = (reg & 0x08000000) ? TRUE : FALSE;
    if (arg0 != 0) {
        p = lbl_804DE4E0;
        reg |= 0x08000000;
        *p++ = 0;
        *p++ = 0;
        *p++ = 0;
        *p = 0;
    } else {
        reg &= ~0x08000000;
    }
    reg &= ~0x80000001;
    SI_HW_REGS[SI_SICOMSCR] = reg;
    OSRestoreInterrupts(enabled);
    return rc;
}
