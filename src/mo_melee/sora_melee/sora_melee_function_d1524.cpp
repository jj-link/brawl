#include <types.h>
#pragma force_active on

namespace {
    struct S {
        u32 unk0;
        u32 unk4;
        u32 unk8;
    };
}

extern "C" unsigned int fn_27_D1524(S* s)
{
    return (s->unk8 >> 16) & 1;
}
