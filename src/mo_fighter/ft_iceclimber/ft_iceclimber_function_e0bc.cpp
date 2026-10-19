#include <types.h>
#pragma force_active on

extern "C" s32 fn_105_E114();

extern "C" float fn_105_E0BC(u8* base, void* unused, s32 i, s32 j) {
    s32 k = fn_105_E114();
    u8* p = base + k * 0xf4;
    p = p + (i << 2);
    float* arr = *(float**)(p - 0x3e70);
    return arr[j];
}
