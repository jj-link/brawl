#include <types.h>
#pragma force_active on

extern "C" s32 fn_104_AE30();

extern "C" float fn_104_1BA78(u8* base, void* unused, s32 i, s32 j) {
    u8* p = base + fn_104_AE30() * 0x7c;
    p = p + i * 4;
    float* arr = *(float**)(p - 0x3e70);
    return arr[j];
}
