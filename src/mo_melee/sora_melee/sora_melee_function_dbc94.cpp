#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_DBC94(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)((x << 6) & 0xF0000000) >> 29;
}
