#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A1330(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    s32 v = (s32)(((x >> 25) & 0xF) << 28);
    return v >> 29;
}
