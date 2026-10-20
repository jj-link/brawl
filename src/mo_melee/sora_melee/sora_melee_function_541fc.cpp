#pragma force_active on
typedef unsigned int u32;
typedef short s16;

struct FnStruct {
    u32 unk0;
    u32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" {
void fn_27_541FC(FnStruct* dst, u32* src, u32 val, s16* src2, s16 val2)
{
    s16 b;
    src = (u32*)*src;
    b = *src2;
    dst->unk0 = (u32)src;
    dst->unk4 = val;
    dst->unk8 = b;
    dst->unkA = val2;
}
}
