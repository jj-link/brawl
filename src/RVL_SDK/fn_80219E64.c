#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern unsigned char *lbl_804F6810[];

void fn_80219E64(s32 arg0, s32 arg1, s16 *arg2) {
    unsigned char *state = lbl_804F6810[arg0];
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (arg2 != 0) {
        switch (arg1) {
        case 0:
            arg2[0] = (s16)(*(s16 *)(state + 0x87A) - *(s16 *)(state + 0x874));
            arg2[1] = (s16)(*(s16 *)(state + 0x87C) - *(s16 *)(state + 0x876));
            arg2[2] = (s16)(*(s16 *)(state + 0x87E) - *(s16 *)(state + 0x878));
            break;
        case 1:
            arg2[0] = (s16)(*(s16 *)(state + 0x894) - *(s16 *)(state + 0x88E));
            arg2[1] = (s16)(*(s16 *)(state + 0x896) - *(s16 *)(state + 0x890));
            arg2[2] = (s16)(*(s16 *)(state + 0x898) - *(s16 *)(state + 0x892));
            break;
        }
    }
    OSRestoreInterrupts(enabled);
}