#include <stddef.h>
#pragma force_active on

typedef unsigned int u32;
typedef int s32;

typedef struct WorkBuffer
{
    u32 reserved[3];
    s32 *intWorks;
} WorkBuffer;

extern "C" void fn_123_A528(WorkBuffer *work, s32 value, u32 index)
{
    work->intWorks[index] *= value;
}
