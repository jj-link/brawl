#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_19AE68(Obj* p)
{
    u32 x = p->unk8;
    s32 t = (s32)(((x << 5) | (x >> 27)) & 0xFC000000u);
    return t >> 27;
}
}
