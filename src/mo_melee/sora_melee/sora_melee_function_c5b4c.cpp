#include <types.h>
#pragma force_active on

extern "C" {
char* fn_27_C5B4C(char* p, s32 idx)
{
    s32 t = *(s32*)(p + 8) >> 30;
    s32 n = t + idx;
    if (n >= 1) {
        n = n - 1;
    }
    return p + (n << 3) + 12;
}
}
