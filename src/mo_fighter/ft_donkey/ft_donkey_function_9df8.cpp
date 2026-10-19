#include <types.h>
#pragma force_active on

extern "C" s32 fn_92_9E50();

extern "C" float fn_92_9DF8(u8* base, s32, s32 a, s32 b) {
    u8* p = base + fn_92_9E50() * 0x6C;
    float* table = *(float**)(p + a * 4 - 0x3E70);
    return table[b];
}
