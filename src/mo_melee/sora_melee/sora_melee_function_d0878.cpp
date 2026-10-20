#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D0878(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    u32 x = (v >> 10) & 0xFF;
    return ((s32)(x << 24)) >> 25;
}
