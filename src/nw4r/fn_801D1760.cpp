#include <types.h>
#pragma force_active on

extern "C" void fn_801B9AC4(s32, s32);

extern "C" void fn_801D1760(u8* base, s32 idx, s32 arg) {
    s32* p = (s32*)(base + idx * 16);
    s32 i = 0;
    for (; i < *(s32*)(base + 0xA0); i++) {
        if (p[3] != 0) {
            fn_801B9AC4(p[3], arg);
        }
        p++;
    }
}
