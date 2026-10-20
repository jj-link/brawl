#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1B2900(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return ((s32)((v << 8) & 0xF8000000)) >> 28;
}
