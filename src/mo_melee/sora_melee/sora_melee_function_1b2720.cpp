#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1B2720(void* p)
{
    u32 v = *(u32*)((char*)p + 8);
    u32 r = (v << 8) | (v >> 24);
    r &= 0xF8000000;
    return (s32)r >> 28;
}
