#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u16 lbl_804FD408[];

unsigned short fn_8022E238(char index) {
    BOOL enabled;
    unsigned short v;

    enabled = OSDisableInterrupts();
    if (index >= 0 && index < 0x10) {
        v = lbl_804FD408[index];
    } else {
        v = 0;
    }
    OSRestoreInterrupts(enabled);
    return v;
}
