#include <types.h>
#pragma force_active on

extern "C" void fn_94_B080(u8* work, s32 value, u32 index)
{
    s32* arr = *(s32**)(work + 0xc);
    arr[index] -= value;
}
