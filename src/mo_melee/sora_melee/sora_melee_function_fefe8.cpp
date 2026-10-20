#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_FEFE8(void* p) {
    u32 x = ((u32*)p)[2];
    u32 r = (x << 4) | (x >> 28);
    return ((s32)(r & 0xF8000000)) >> 28;
}
