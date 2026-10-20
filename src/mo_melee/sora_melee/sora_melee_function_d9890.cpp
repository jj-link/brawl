#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_D9890(char* self, s32 idx)
{
    s32 i = (*(s32*)(self + 0x8) >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return self + i * 0x68 + 0xc;
}
}
