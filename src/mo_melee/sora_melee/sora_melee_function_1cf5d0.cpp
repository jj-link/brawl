#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1CF5D0(void* self, s32 idx) {
    s32 t = ((s32*)self)[2] >> 29;
    s32 n = t + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (u8*)self + n * 12 + 12;
}
