#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D0CDC(void *p) {
    u32 x = *(u32 *)((u8 *)p + 8);
    u32 r = ((x << 7) | (x >> 25)) & 0xFF000000;
    return (s32)r >> 25;
}
