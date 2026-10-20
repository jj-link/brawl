#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_C6F60(u8* p) {
    u32 x = *(u32*)(p + 8);
    u32 y = ((x << 5) | (x >> 27)) & 0xFC000000;
    return (s32)y >> 27;
}
}
