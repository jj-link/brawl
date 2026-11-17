#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern int fn_80212C08(int, int, void *, int, void *, int, void (*)(void), void *);
extern void fn_801E2988(void);
extern unsigned int lbl_804DDF60[8];
extern unsigned int lbl_804DDF80[8];
extern int lbl_805A0714;
extern int lbl_805A0718;
extern void (*lbl_805A0720)(void);
void (*OSSetPowerCallback(void (*callback)(void)))(void) {
    int inner_state;
    int outer_state;
    void (*old_callback)(void);
    unsigned long result;
    outer_state = OSDisableInterrupts();
    old_callback = lbl_805A0720;
    lbl_805A0720 = callback;
    if (lbl_805A0718 == 0) {
        inner_state = OSDisableInterrupts();
        result = fn_80212C08(lbl_805A0714, 0x1000, lbl_804DDF60, 0x20,
                             lbl_804DDF80, 0x20, fn_801E2988, 0);
        if (result == 0) {
            lbl_805A0718 = 1;
        } else {
            *(unsigned int *)&lbl_805A0718 = 0;
        }
        OSRestoreInterrupts(inner_state);
    }
    OSRestoreInterrupts(outer_state);
    return old_callback;
}