#include <types.h>
#pragma force_active on

extern "C" s32 fn_125_B690();

extern "C" float fn_125_B638(u8* base, s32 unused, s32 i, s32 j) {
    u8* p = base + fn_125_B690() * 0x78;
    p = p + i * 4;
    float* arr = *(float**)(p - 0x3E70);
    return arr[j];
}
