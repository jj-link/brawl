#include <types.h>
#pragma force_active on

extern "C" s32 fn_122_FB44();

extern "C" float fn_122_FAEC(u8* base, void* unused, s32 a, s32 b) {
    u8* p = base + fn_122_FB44() * 0x68;
    p += a * 4;
    float* arr = *(float**)(p - 0x3E70);
    return arr[b];
}
