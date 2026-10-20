#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D92C8(u8* p, s32 idx) {
    s32 v = *(s32*)(p + 8);
    s32 n = (v >> 25) + idx;
    if (n >= 0x2b) {
        n -= 0x2b;
    }
    return p + n * 0x30 + 0xc;
}
