#include <types.h>
#pragma force_active on

extern "C" void fn_121_B2C8(void* self, u32 index, float value)
{
    float* arr = *(float**)((char*)self + 0x14);
    arr[index] += value;
}
