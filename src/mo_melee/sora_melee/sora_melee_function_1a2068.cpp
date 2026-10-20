#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A2068(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    u32 r = (x << 5) | (x >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
