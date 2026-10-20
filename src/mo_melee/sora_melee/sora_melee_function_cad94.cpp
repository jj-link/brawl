#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CAD94(void* p) {
    u32 w = *(u32*)((u8*)p + 8);
    s32 v = (s32)((w << 8) & 0xF8000000);
    return v >> 28;
}
