#include <types.h>
#pragma force_active on

extern "C" s32 fn_125_B690();

extern "C" s32 fn_125_B69C(u8* base, s32 unused, s32 i, s32 j) {
    u8* p = base - 0x10000 + fn_125_B690() * 0x34;
    p = p + i * 4;
    s32* arr = *(s32**)(p - 0x7600);
    return arr[j];
}
