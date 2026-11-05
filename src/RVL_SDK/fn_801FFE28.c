#include <revolution/OS/OSInterrupt.h>
#include <string.h>
#pragma force_active on

extern int lbl_805A0A5C;
extern int lbl_805A0A68;
extern int lbl_805A0A74;

void fn_801FFE28(int arg0, int arg1) {
    BOOL enabled = OSDisableInterrupts();
    lbl_805A0A68 = arg0;
    lbl_805A0A5C = arg1;
    if (arg0 == 0) {
        memset(&lbl_805A0A74, 1, 3);
    }
    OSRestoreInterrupts(enabled);
}
