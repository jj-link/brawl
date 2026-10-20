#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_19AC84(void* self)
{
    return (s32)((*(u32*)((char*)self + 8) & 0x0E000000) << 4) >> 30;
}
