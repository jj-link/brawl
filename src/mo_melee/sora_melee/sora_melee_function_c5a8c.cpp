#pragma force_active on
typedef unsigned int u32;
typedef short s16;

struct Fn27Dst {
    u32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_C5A8C(Fn27Dst* dst, const u32* src, u32 val, const s16* hsrc, s16 hval)
{
    dst->unk0 = *src;
    dst->unk4 = val;
    dst->unk8 = *hsrc;
    dst->unkA = hval;
}
