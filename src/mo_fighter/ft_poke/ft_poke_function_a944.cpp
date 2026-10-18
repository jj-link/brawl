#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;
typedef int s32;

extern "C" void fn_116_A944(void* self, s32 value, u32 index)
{
    s32* arr = *(s32**)((char*)self + 0xc);
    arr[index] -= value;
}
