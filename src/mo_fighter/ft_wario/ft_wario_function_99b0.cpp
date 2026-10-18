#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;
typedef int s32;

typedef struct Work
{
    u32 pad0;
    u32 pad4;
    u32 pad8;
    s32 *values;
} Work;

extern "C" void fn_110_99B0(Work *work, s32 value, u32 index)
{
    work->values[index] -= value;
}
