#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_FF210(void* p) {
    u32 x = ((u32*)p)[2];
    s32 t = (s32)(((x >> 25) & 0xF) << 28);
    return t >> 29;
}
