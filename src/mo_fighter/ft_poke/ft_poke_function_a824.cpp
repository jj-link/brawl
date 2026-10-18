#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_116_A824(u8* self, u32 mask, u32 index)
{
    u32* arr = *(u32**)(self + 0x1c);
    arr[index] |= mask;
}
