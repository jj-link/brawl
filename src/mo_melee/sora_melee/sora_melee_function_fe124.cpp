#include <types.h>
#pragma force_active on

struct FE124Out {
    u32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" {
void fn_27_FE124(FE124Out* out, const u32* src, u32 val, const s16* half, s16 val2)
{
    u32 v = *src;
    out->unk0 = v;
    s16 h = *half;
    out->unk4 = val;
    out->unk8 = h;
    out->unkA = val2;
}
}
