#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on
extern unsigned char lbl_804FBD58[];
extern unsigned char lbl_805A0C71;
extern unsigned char *lbl_804F6810[];
extern int fn_80219F3C(int, int);
extern void fn_8021A68C(int, int, int (*)(int, int));
void fn_80219F60(int index) {
    int value;
    unsigned char *state;
    BOOL enabled;
    memset(lbl_804FBD58 + (index + 10) * 0x46 + 1, 0, 0x46);
    lbl_805A0C71 = 1;
    state = lbl_804F6810[index];
    enabled = OSDisableInterrupts();
    value = *(int *)(state + 0x8bc);
    OSRestoreInterrupts(enabled);
    if (value != -1) {
        enabled = OSDisableInterrupts();
        if (state[0x986]) {
            OSRestoreInterrupts(enabled);
            return;
        }
        state[0x986] = 1;
        OSRestoreInterrupts(enabled);
        fn_8021A68C(index, 0, fn_80219F3C);
    }
}