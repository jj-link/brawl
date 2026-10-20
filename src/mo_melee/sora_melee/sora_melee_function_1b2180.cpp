#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_1B2180(void *p) {
    u32 v = ((u32 *)p)[2];
    u32 r = (v << 8) | (v >> 24);
    return (s32)(r & 0xF8000000) >> 28;
}
}
