#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFD14(u8* p, s32 idx) {
    s32 t = *(s32*)(p + 8) >> 22;
    s32 n = t + idx;
    if (n >= 0x12d) {
        n -= 0x12d;
    }
    return p + n * 4 + 0xc;
}
