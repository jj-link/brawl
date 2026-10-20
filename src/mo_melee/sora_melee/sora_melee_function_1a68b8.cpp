#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A68B8(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)(((v >> 1) & 0x7FF) << 21) >> 22;
}
