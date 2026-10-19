#include <types.h>
#pragma force_active on

extern "C" void* fn_73_ADC8(u8* base, s32 index) {
    s32 v = *(s32*)(base + 8);
    s32 t = (v >> 28) + index;
    if (t >= 7) {
        t -= 7;
    }
    return base + 12 + t * 8;
}
