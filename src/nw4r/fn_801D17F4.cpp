#include <types.h>
#pragma force_active on

extern "C" void fn_801B8A5C(s32, s32, s32);

extern "C" void fn_801D17F4(u8* base, s32 idx, s32 a, s32 b)
{
    s32* p = (s32*)(base + idx * 16);
    s32 i;

    for (i = 0; i < *(s32*)(base + 0xA0); i++) {
        if (p[3] != 0) {
            fn_801B8A5C(p[3], a, b);
        }
        p++;
    }
}
