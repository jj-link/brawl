#include <types.h>
#pragma force_active on

extern "C" void* fn_27_FE9D4(void* self, s32 idx) {
    s32 v = ((s32*)self)[2] >> 29;
    s32 n = v + idx;
    if (n >= 3) {
        n -= 3;
    }
    return (char*)self + n * 12 + 12;
}
