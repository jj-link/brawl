#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A11FC(const u32 *p) {
    u32 x = p[2] & 0x003F0000;
    x <<= 10;
    return (s32)x >> 27;
}
