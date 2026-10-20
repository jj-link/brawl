#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFAE4(void* p, s32 idx) {
    s32 v = ((s32*)p)[2] >> 27;
    s32 n = v + idx;
    if (n >= 12) {
        n -= 12;
    }
    return (char*)p + n * 4 + 12;
}
