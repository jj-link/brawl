#include <types.h>
#pragma force_active on

extern "C" void* fn_27_F660C(char* self, s32 idx) {
    s32 n = (*(s32*)(self + 0x18) >> 30) + idx;
    if (n >= 1) {
        n = n - 1;
    }
    return self + n * 12 + 0x1c;
}
