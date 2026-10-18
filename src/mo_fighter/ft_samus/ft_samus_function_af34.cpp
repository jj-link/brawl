#include <stddef.h>
#pragma force_active on

extern "C" void fn_94_AF34(void* obj, unsigned int mask, unsigned int index)
{
    unsigned int* arr = *(unsigned int**)((char*)obj + 0x1c);
    arr[index] &= ~mask;
}
