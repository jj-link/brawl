#include <types.h>
#pragma force_active on

extern "C" s32 fn_92_9E50();

extern "C" s32 fn_92_9E5C(void* base, void*, s32 parameter, s32 element) {
    u32* table = (u32*)((u8*)base - 0x17618 + fn_92_9E50() * 0x3C + parameter * 4);
    return ((u32*)*table)[element];
}
