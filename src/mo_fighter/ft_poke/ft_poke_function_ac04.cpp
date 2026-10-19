#include <types.h>
#pragma force_active on

extern "C" s32 fn_116_AC5C();

extern "C" float fn_116_AC04(u8* base, s32, s32 a, s32 b) {
    u8* row = base + fn_116_AC5C() * 0x6c;
    float* p = *(float**)(row + a * 4 - 0x3E70);
    return p[b];
}
