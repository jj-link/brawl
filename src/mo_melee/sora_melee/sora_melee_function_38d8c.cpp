#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_38D8C(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)(((x >> 23) & 0x1F) << 27) >> 28;
}
