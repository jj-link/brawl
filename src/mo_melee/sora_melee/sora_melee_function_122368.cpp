#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_122368(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    u32 r = (x << 12) | (x >> 20);
    return ((s32)(r & 0xFE000000)) >> 26;
}
