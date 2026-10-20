#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CEEF8(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    s32 v = (s32)((x << 12) & 0xFE000000);
    return v >> 26;
}
