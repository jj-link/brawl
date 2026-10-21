#include <revolution/types.h>
#pragma force_active on

extern char lbl_804FB4A0[];

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int status);

u8 fn_8022E2F0(void) {
    int enabled;
    u8 temp_r31;

    enabled = OSDisableInterrupts();
    temp_r31 = lbl_804FB4A0[0x6E5];
    OSRestoreInterrupts(enabled);
    return temp_r31;
}
