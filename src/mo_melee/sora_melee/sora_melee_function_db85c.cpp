#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_DB85C(u32* p) {
    u32 x = p[2];
    u32 r = (x << 14) | (x >> 18);
    return (s32)(r & 0xFF000000) >> 25;
}
