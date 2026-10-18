#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;

typedef struct FloatArrayHolder
{
    unsigned char pad[0x14];
    float *values;
} FloatArrayHolder;

extern "C" void fn_119_999C(FloatArrayHolder *self, u32 index, float value)
{
    self->values[index] += value;
}
