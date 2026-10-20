#include <types.h>
#pragma force_active on

extern "C" void* fn_27_FED6C(void* p, s32 idx)
{
    s32 v = *(s32*)((char*)p + 8) >> 26;
    s32 n = v + idx;
    if (n >= 0x16) {
        n -= 0x16;
    }
    return (char*)p + n * 0xC + 0xC;
}
