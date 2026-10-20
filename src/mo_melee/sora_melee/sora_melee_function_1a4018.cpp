#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A4018(void* p) {
    u32 w = *(u32*)((u8*)p + 8);
    u32 r = (w << 20) | (w >> 12);
    return (s32)(r & 0xFFE00000) >> 22;
}
