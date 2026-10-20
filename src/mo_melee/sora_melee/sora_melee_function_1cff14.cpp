#include <types.h>
#pragma force_active on

extern "C" int fn_27_1CFF14(void *ptr)
{
    u32 val = *(u32*)((u8*)ptr + 8);
    return (val >> 19) & 1;
}
