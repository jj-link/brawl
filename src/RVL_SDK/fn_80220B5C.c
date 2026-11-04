#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern u8* lbl_804F6810[];

void fn_80220B5C(s32 arg0, u8* arg1)
{
    u8* state = lbl_804F6810[(u8)arg0];
    u8* out = state + 0xA0 + state[0x8C8] * 0x60;
    s32 i;
    BOOL enabled;

    for (i = 0; i < 0x60; i++) {
        out[i] = 0;
    }
    *(u16*)(out + 0) = (arg1[1] | (arg1[2] << 8)) & 0x9F1F;
    if (*(u32*)(state + 0x8B8) <= 1U) {
        out[0x29] = 0;
    } else {
        *(s8*)(out + 0x29) = -4;
    }
    out[0x28] = state[0x8C1];
    *(s32*)(state + 0x848) = (arg1[1] >> 7) & 1;
    *(s16*)(out + 2) = (s16)((s16)((s16)(arg1[3] << 2) & ~3) | ((arg1[1] >> 5) & 3)) - *(s16*)(state + 0x874);
    *(s16*)(out + 4) = (s16)((s16)((s16)(arg1[4] << 2) & ~3) | (s16)((arg1[2] >> 4) & 2)) - *(s16*)(state + 0x876);
    *(s16*)(out + 6) = (s16)((s16)((s16)(arg1[5] << 2) & ~3) | (s16)((arg1[2] >> 5) & 2)) - *(s16*)(state + 0x878);
    enabled = OSDisableInterrupts();
    state[0x8C8] = state[0x8C8] == 0;
    OSRestoreInterrupts(enabled);
}
