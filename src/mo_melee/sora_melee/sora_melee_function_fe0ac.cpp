#include <types.h>
#pragma force_active on

struct FE0AC_Dst {
    s32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_FE0AC(FE0AC_Dst* dst, s32* src, u32 val, s16* src2, s16 val2)
{
    src = (s32*)*src;
    s16 b = *src2;
    dst->unk0 = (s32)src;
    dst->unk4 = val;
    dst->unk8 = b;
    dst->unkA = val2;
}
