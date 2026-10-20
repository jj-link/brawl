#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Fn27Obj {
    int unk0;
    int unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1A0A10(Fn27Obj *p)
{
    u32 v = p->unk8;
    u32 r = (v << 5) | (v >> 27);
    return (s32)(r & 0xFC000000) >> 27;
}
