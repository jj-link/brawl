#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_112_AA2C(u8* self, u32 index, float value)
{
    float* arr = *(float**)(self + 0x14);
    arr[index] *= value;
}
