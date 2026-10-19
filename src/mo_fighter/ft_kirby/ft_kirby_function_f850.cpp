#include <types.h>
#pragma force_active on

extern "C" s32 fn_96_F8A8();

extern "C" float fn_96_F850(u8* self, void* unused, s32 x, s32 y) {
    u8* base = (u8*)self + fn_96_F8A8() * 0x490;
    float* table = *(float**)(base + x * 4 - 0x3E70);
    return table[y];
}
