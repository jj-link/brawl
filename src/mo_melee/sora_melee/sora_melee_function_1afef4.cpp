#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFEF4(void* p, s32 idx) {
    s32 x = (*(s32*)((char*)p + 8) >> 22) + idx;
    if (x >= 0x118) {
        x -= 0x118;
    }
    return (char*)p + x * 4 + 0xc;
}
