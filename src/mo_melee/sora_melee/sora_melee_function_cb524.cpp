#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_27_CB524(s32* p) {
    return (s32)((u32)(p[2] << 2) & 0xE0000000) >> 30;
}
}
