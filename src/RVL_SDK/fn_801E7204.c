#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
extern unsigned int lbl_80474EB0[];
extern int lbl_80474E98[];
extern s64 lbl_804DE3D0[];
extern int lbl_805A0788;
extern s64 fn_801E1B54(void);
extern void fn_801E6F54(void);
extern void fn_801E6DE8(int, void*, int, void*, int, void (*)(void), int, unsigned int);

unsigned int fn_801E7204(int chan) {
    BOOL enabled = OSDisableInterrupts();
    unsigned int status = lbl_80474EB0[chan];
    s64 elapsed = fn_801E1B54() - lbl_804DE3D0[chan];
    if (lbl_80474E98[1] & (0x80 >> chan)) {
        if (status != 8) {
            lbl_804DE3D0[chan] = fn_801E1B54();
            OSRestoreInterrupts(enabled);
            return status;
        }
        lbl_80474EB0[chan] = 0x80;
        status = 0x80;
    } else {
        unsigned int ticks = OS_BUS_CLOCK_SPEED / 4 / 1000;
        if (elapsed <= ticks * 50 && status != 8) {
            OSRestoreInterrupts(enabled);
            return status;
        }
        if (elapsed <= ticks * 75) {
            lbl_80474EB0[chan] = 0x80;
        } else {
            lbl_80474EB0[chan] = 0x80;
            status = 0x80;
        }
    }
    lbl_804DE3D0[chan] = fn_801E1B54();
    fn_801E6DE8(chan, &lbl_805A0788, 1, &lbl_80474EB0[chan], 3, fn_801E6F54, 0, (OS_BUS_CLOCK_SPEED / 4 / 125000) * 65 / 8);
    OSRestoreInterrupts(enabled);
    return status;
}