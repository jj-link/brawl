#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_199374(void *p) {
    u32 x = *(u32 *)((u8 *)p + 8);
    return (s32)(((x << 4) | (x >> 28)) & 0xF8000000) >> 28;
}
}
