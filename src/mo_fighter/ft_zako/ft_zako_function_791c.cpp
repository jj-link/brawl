#include <types.h>
#pragma force_active on

extern "C" s32 fn_126_7974();

extern "C" float fn_126_791C(u8* base, void* unused, s32 a, s32 b) {
    u8* p = base + fn_126_7974() * 8;
    p = p + a * 4;
    float* t = *(float**)(p - 0x3E70);
    return t[b];
}
