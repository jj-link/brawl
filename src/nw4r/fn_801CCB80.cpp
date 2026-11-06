#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u8 pad4[4];
    u32 unk8;
    u8 padC[4];
    u32 unk10;
    u8 unk14[1];
} A;

extern "C" void fn_801CCB80(A *arg0, u32 arg1) {
    BOOL status = OSDisableInterrupts();
    u32 idx = (arg1 - arg0->unk0) / arg0->unk8;
    u8 *p = (u8 *)arg0 + (idx >> 3);
    p[0x14] &= ~(1 << (idx & 7));
    arg0->unk10--;
    OSRestoreInterrupts(status);
}
