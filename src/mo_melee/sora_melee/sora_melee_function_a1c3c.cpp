#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_A1C3C(void *p) {
    u32 x = *(u32 *)((u8 *)p + 8);
    return (s32)((x << 10) & 0xFC000000) >> 27;
}
