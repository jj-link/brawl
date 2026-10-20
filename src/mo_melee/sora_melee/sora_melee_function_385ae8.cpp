#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_385AE8(void* p)
{
    s32* field = (s32*)((char*)p + 8);
    return *field >> 22;
}
