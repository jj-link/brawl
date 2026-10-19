#include <types.h>
#pragma force_active on

extern "C" s32 fn_110_9CC8();

extern "C" float fn_110_1FB80(u8* base, void* unused, s32 a, s32 b) {
    u8* p = base + fn_110_9CC8() * 0x78;
    float* table = *(float**)(p + a * 4 - 0x3E70);
    return table[b];
}
