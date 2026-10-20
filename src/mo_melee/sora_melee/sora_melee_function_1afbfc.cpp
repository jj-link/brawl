#include <types.h>
#pragma force_active on

extern "C" void* fn_27_1AFBFC(char* p, s32 idx) {
    s32 n = (*(s32*)(p + 8) >> 22) + idx;
    n = (n >= 0x1c0) ? n - 0x1c0 : n;
    return p + n * 4 + 0xc;
}
