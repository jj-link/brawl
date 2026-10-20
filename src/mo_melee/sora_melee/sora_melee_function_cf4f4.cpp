#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CF4F4(void *p) {
    u32 x = ((u32 *)p)[2];
    return (s32)((x << 6) & 0xFE000000) >> 26;
}
