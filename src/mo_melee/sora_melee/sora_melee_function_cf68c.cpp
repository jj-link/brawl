#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CF68C(void* p)
{
    u32 v = *(u32*)((u8*)p + 8);
    return (s32)((v << 6) & 0xFE000000) >> 26;
}
