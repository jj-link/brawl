#include <types.h>
#pragma force_active on

extern "C" void fn_76_3D2C(void* ptr)
{
    unsigned int* p = (unsigned int *)((char *)ptr + 0x8);
    *p = *p | 0x10000u;
}
