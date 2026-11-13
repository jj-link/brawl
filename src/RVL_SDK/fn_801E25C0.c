#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int fn_802123A8(char *, int);
extern int fn_80212C08(int, int, void *, int, void *, int, void (*)(void), void *);
extern void fn_801E2980(void);
extern void fn_801E2984(void);
extern void fn_801E2988(void);
extern char lbl_80474B08[];
extern char lbl_80474B1C[];
extern unsigned int lbl_804DDF60[8];
extern unsigned int lbl_804DDF80[8];
extern int lbl_805A0708;
extern int lbl_805A070C;
extern int lbl_805A0710;
extern int lbl_805A0714;
extern int lbl_805A0718;
extern int lbl_805A071C;
extern void (*lbl_805A0720)(void);
extern void (*lbl_805A0724)(void);

int fn_801E25C0(void)
{
    int zero = 0;
    int result;
    int enabled;

    lbl_805A0720 = fn_801E2984;
    lbl_805A0724 = fn_801E2980;
    lbl_805A0708 = zero;
    if (lbl_805A070C != zero) {
        return 1;
    }
    lbl_805A071C = zero;
    result = fn_802123A8(lbl_80474B08, zero);
    lbl_805A0710 = result;
    if (result < zero) {
        lbl_805A070C = zero;
        return zero;
    }
    result = fn_802123A8(lbl_80474B1C, zero);
    lbl_805A0714 = result;
    if (result < zero) {
        lbl_805A070C = zero;
        return zero;
    }
    enabled = OSDisableInterrupts();
    result = fn_80212C08(lbl_805A0714, 0x1000, lbl_804DDF60, 0x20,
                    lbl_804DDF80, 0x20, fn_801E2988, (void *)0);
    if (result == 0) {
        lbl_805A0718 = 1;
    } else {
        *(unsigned int *)&lbl_805A0718 = zero;
    }
    OSRestoreInterrupts(enabled);
    lbl_805A070C = 1;
    return 1;
}
