#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B028C(void* p, s32 idx) {
    s32 v = *(s32*)((u8*)p + 8);
    s32 t = (v >> 27) + idx;
    if (t >= 12) {
        t -= 12;
    }
    return (u8*)p + (t << 4) + 12;
}
