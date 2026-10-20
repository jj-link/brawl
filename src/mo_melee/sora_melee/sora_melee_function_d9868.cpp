#include <types.h>
#pragma force_active on

extern "C" void* fn_27_D9868(u8* self, s32 idx) {
    s32 i = (*(s32*)(self + 8) >> 29) + idx;
    if (i >= 2) {
        i -= 2;
    }
    return self + i * 0x68 + 0xc;
}
