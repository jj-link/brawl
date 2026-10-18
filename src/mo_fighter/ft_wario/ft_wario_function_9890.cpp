#include <types.h>
#pragma force_active on

struct Fn110Work {
    u8 pad[0x1c];
    u32 *flags;
};

extern "C" {
void fn_110_9890(Fn110Work *work, u32 mask, u32 index)
{
    work->flags[index] |= mask;
}
}
