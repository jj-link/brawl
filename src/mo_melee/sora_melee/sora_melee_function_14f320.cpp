#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_14F320(void* p) {
    u32 x = ((u32*)p)[2];
    u32 t = (x << 7) | (x >> 25);
    t &= 0xFF000000;
    return (s32)t >> 25;
}
