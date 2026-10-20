#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B0354(u8* p, s32 idx) {
    s32 v = *(s32*)(p + 8);
    s32 i = (v >> 26) + idx;
    if (i >= 0x11) {
        i -= 0x11;
    }
    return p + i * 0x60 + 0xc;
}
