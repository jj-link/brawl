#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct S {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1D0314(S* p)
{
    u32 x = p->unk8;
    u32 r = (x << 7) | (x >> 25);
    return (s32)(r & 0xFF000000) >> 25;
}
