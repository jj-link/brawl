#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern unsigned char lbl_804FB4A0[];

s32 fn_8022D228(void) {
    unsigned char* base = lbl_804FB4A0;
    int enabled = OSDisableInterrupts();
    if (base[0xC] == 0 && base[0xD] == 0 && base[0xF] == 4 && base[0x10] == 5) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
