#include <types.h>
#pragma force_active on

namespace {
    struct Bits {
        u32 pad0[2];
        s32 bits;
    };
}

extern "C" s32 fn_27_1D0240(const Bits* p)
{
    return p->bits >> 25;
}
