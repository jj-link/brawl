#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D9AC0(char* base, s32 idx) {
    s32 v = ((s32*)base)[2];
    s32 n = (v >> 27) + idx;
    if (n >= 15) {
        n -= 15;
    }
    return base + n * 0x24 + 0xc;
}
