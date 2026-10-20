#include <types.h>
#pragma force_active on

struct FdfbcStruct {
    u32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_FDFBC(FdfbcStruct* dst, const u32* src, u32 val, const s16* half, s16 val2)
{
    dst->unk0 = *src;
    dst->unk4 = val;
    dst->unk8 = *half;
    dst->unkA = val2;
}
