#include <types.h>
#pragma force_active on

struct fn_27_557EC_Pair {
    u32 unk0;
    u32 unk4;
};

extern "C" void fn_27_557EC(fn_27_557EC_Pair* dst, const fn_27_557EC_Pair* src, u32 val)
{
    dst->unk0 = src->unk0;
    dst->unk4 = val;
}
