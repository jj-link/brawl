#include <types.h>
#pragma force_active on

extern "C" s32 fn_112_AE1C();

extern "C" float fn_112_ADC4(u8* base, void* unused, s32 a, s32 b) {
    s32 idx = fn_112_AE1C();
    u8* p = base + idx * 0x7c;
    p = p + a * 4;
    float* arr = *(float**)(p - 0x3e70);
    return arr[b];
}
