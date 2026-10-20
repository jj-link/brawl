#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A5C88(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)(((x << 20) | (x >> 12)) & 0xFFE00000) >> 22;
}
