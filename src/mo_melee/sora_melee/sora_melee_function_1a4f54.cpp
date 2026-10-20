#include <types.h>
#pragma force_active on

extern "C" {
int fn_27_1A4F54(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    return (s32)((x << 4 | x >> 28) & 0xE0000000) >> 30;
}
}
