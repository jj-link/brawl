#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2EBA3C(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    u32 r = ((v << 6) | (v >> 26)) & 0xF0000000;
    return ((s32)r) >> 29;
}
