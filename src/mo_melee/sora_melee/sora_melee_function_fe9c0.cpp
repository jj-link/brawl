#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_FE9C0(void* p)
{
    u32* ptr = (u32*)p;
    return (ptr[2] >> 22) & 1;
}
