#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CF6F0(void* p) {
    u32 v = ((u32*)p)[2];
    s32 x = (s32)(((v >> 13) & 0x7F) << 25);
    return x >> 26;
}
