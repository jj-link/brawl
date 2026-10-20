#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_2AE0C4(void* p) {
    u32 w = *(u32*)((u8*)p + 8);
    return (s32)((w << 2) & 0xE0000000) >> 30;
}
