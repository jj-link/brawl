#include <types.h>
#pragma force_active on

extern "C" u32 fn_114_15D90(const void* obj, s32 unused, s32 index) {
    const u8* p = (const u8*)obj;
    s32 n = *(const s32*)(p + 0x18);
    return *(const u32*)(p + 0x3c + ((index - n) << 2));
}
