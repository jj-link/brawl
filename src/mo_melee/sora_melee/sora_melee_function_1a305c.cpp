#include <types.h>
#pragma force_active on

namespace {
    struct UnkStruct {
        u32 m0x00;
        u32 m0x04;
        s32 m0x08;
    };
}

extern "C" s32 fn_27_1A305C(const UnkStruct* p)
{
    return p->m0x08 >> 29;
}
