#include <types.h>
#pragma force_active on

extern "C" s32 fn_94_B398();

extern "C" float fn_94_1880C(u8* base, s32 unused, s32 a, s32 b)
{
    u8* p = base + fn_94_B398() * 0x38;
    p = p + a * 4;
    float* arr = *(float**)(p - 0x3E70);
    return arr[b];
}
