#include <types.h>
#pragma force_active on

extern "C" s32 fn_113_D0AC();

extern "C" float fn_113_D054(u8* base, void* unused, s32 i, s32 j) {
    u8* p = base + fn_113_D0AC() * 60;
    p = p + i * 4;
    float* arr = *(float**)(p - 0x3E70);
    return arr[j];
}
