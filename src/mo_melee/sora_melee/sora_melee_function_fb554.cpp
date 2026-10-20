#include <types.h>
#pragma force_active on

extern "C" void* fn_27_FB554(u8* p, s32 idx) {
    s32 n = (*(s32*)(p + 0x18) >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return p + 0x1c + n * 12;
}
