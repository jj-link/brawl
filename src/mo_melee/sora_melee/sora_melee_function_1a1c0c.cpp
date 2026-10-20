#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A1C0C(u32* p) {
    u32 v = p[2];
    return ((s32)((v << 3) & 0xF0000000u)) >> 29;
}
