#include <stddef.h>
#pragma force_active on

extern "C" void fn_115_A320(void* self, unsigned int index)
{
    unsigned int* arr = *(unsigned int**)((char*)self + 0x1c);
    arr[index] = 0;
}
