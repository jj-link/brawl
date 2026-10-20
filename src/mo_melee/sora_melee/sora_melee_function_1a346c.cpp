#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A346C(void* p)
{
    s32* field = (s32*)((u8*)p + 8);
    return *field >> 22;
}
