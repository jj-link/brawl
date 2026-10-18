#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

extern "C" void fn_120_9A18(unsigned char* work, u32 mask, u32 index)
{
    u32* flags = *(u32**)(work + 0x1c);
    flags[index] &= ~mask;
}
