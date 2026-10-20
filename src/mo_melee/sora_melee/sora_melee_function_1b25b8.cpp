#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1B25B8(void* p) {
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)(((v << 4) | (v >> 28)) & 0xE0000000) >> 30;
}
