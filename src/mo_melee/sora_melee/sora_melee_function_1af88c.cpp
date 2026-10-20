#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AF88C(void* self, s32 idx) {
    s32 t = *(s32*)((u8*)self + 8) >> 22;
    s32 sum = t + idx;
    if (sum >= 0x122) {
        sum -= 0x122;
    }
    return (u8*)self + sum * 4 + 12;
}
