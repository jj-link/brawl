#include <types.h>
#pragma force_active on
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL status);
extern u16 lbl_804FB4A0[];

u32 fn_8022BB68(void) {
    BOOL enabled = OSDisableInterrupts();
    u16 low = lbl_804FB4A0[0x3A2];
    u16 high = lbl_804FB4A0[0x3A3];
    u32 result = (u32)(high - low) & 0xFF;
    OSRestoreInterrupts(enabled);
    return result;
}
