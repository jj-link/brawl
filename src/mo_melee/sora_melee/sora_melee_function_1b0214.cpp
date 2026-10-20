#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1B0214(void* p, s32 idx) {
    s32 t = ((s32*)p)[2] >> 28;
    s32 k = t + idx;
    if (k >= 4) {
        k -= 4;
    }
    return (char*)p + (k << 4) + 12;
}
