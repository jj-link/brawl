#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A6854(void* p) {
    u32 x = ((u32*)p)[2];
    return (s32)((x << 10) & 0xFFE00000) >> 22;
}
