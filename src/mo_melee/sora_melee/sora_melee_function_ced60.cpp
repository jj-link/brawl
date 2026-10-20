#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CED60(void* p)
{
    u32 w = *(u32*)((char*)p + 8);
    return ((s32)(((w >> 13) & 0x7F) << 25)) >> 26;
}
