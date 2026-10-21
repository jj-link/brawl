#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    u8 pad[0x1c];
    u32 unk1c;
    u8 pad2[0x82];
    u16 unkA2;
    u16 unkA4;
} A;

void fn_80202444(A *arg0, u32 arg1) {
    BOOL status = OSDisableInterrupts();
    arg0->unkA2 = (u16)(arg1 >> 16);
    arg0->unkA4 = (u16)arg1;
    arg0->unk1c |= 0x4000;
    OSRestoreInterrupts(status);
}
