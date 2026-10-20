#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Fn27Src {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" s32 fn_27_2EB910(Fn27Src* p)
{
    s32 t = p->unk8 << 3;
    t &= 0xF0000000;
    return t >> 29;
}
