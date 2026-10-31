#include <types.h>
#pragma force_active on

extern "C" int fn_8019065C(void* arg0, s32 arg1, s32* arg2, s32* arg3, s32* arg4, s32* arg5) {
    u8* e = *(u8**)arg0 + (arg1 / 2) * 0x30;
    s32 oddOffset = (arg1 % 2) * 5;

    if (e[0x8f + oddOffset] == 0) {
        return 0;
    }

    e += oddOffset;

    u32 v = (u32)e[0x90] << 24;
    v |= (u32)e[0x91] << 16;
    v |= (u32)e[0x92] << 8;
    v |= (u32)e[0x93];

    if (arg2 != 0) *arg2 = (v >> 12) & 0xF;
    if (arg3 != 0) *arg3 = (v >> 8) & 0xF;
    if (arg4 != 0) *arg4 = (v >> 4) & 0xF;
    if (arg5 != 0) *arg5 = v & 0xF;

    return 1;
}
