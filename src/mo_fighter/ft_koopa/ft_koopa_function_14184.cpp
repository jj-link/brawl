#include <types.h>
#pragma force_active on

extern "C" s32 fn_102_95D8();

extern "C" float fn_102_14184(u8* base, void* unused, s32 a, s32 b) {
    s32 idx = fn_102_95D8();
    u8* p = base + idx * 0xbc;
    p = p + a * 4;
    float* arr = *(float**)(p - 0x3e70);
    return arr[b];
}
