#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern int lbl_805A0A54;
extern int lbl_805A0A60;
extern int lbl_805A0A6C;

void fn_801FFEF0(int arg0, int arg1) {
    BOOL enabled = OSDisableInterrupts();
    lbl_805A0A60 = arg0;
    lbl_805A0A54 = arg1;
    if (arg0 == 0) {
        memset(&lbl_805A0A6C, 1, 3);
    }
    OSRestoreInterrupts(enabled);
}