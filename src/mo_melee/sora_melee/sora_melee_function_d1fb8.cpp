#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D1FB8(void* p) {
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)((x << 8) & 0xF8000000) >> 28;
}
