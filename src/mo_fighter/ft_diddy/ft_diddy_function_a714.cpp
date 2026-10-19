#include <types.h>
#pragma force_active on

extern "C" s32 fn_115_A76C();

extern "C" float fn_115_A714(u8* base, void*, s32 i, s32 j) {
    u8* p = base + fn_115_A76C() * 0xd8;
    float* arr = *(float**)(p + i * 4 - 0x3e70);
    return arr[j];
}
