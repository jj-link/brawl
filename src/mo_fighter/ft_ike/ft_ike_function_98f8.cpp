#include <types.h>
#pragma force_active on

typedef struct FlagWork {
    char pad[0x1c];
    u32 *flags;
} FlagWork;

extern "C" void fn_119_98F8(FlagWork *work, u32 mask, u32 index)
{
    work->flags[index] &= ~mask;
}
