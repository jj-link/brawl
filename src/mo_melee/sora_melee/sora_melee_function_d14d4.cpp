#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D14D4(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)((x << 5) & 0xFC000000) >> 27;
}
