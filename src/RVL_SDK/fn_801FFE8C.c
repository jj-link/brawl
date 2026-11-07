#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern int lbl_805A0A58;
extern int lbl_805A0A64;
extern int lbl_805A0A70;

void fn_801FFE8C(int arg0, int arg1) {
    BOOL enabled = OSDisableInterrupts();
    lbl_805A0A64 = arg0;
    lbl_805A0A58 = arg1;
    if (arg0 == 0) {
        memset(&lbl_805A0A70, 1, 3);
    }
    OSRestoreInterrupts(enabled);
}
