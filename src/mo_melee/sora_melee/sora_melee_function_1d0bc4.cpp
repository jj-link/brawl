#pragma force_active on
typedef unsigned int u32;

struct fn_27_1D0BC4_obj {
    u32 unk0;
    u32 unk4;
    u32 pad : 4;
    u32 f : 4;
    u32 rest : 24;
};

extern "C" void fn_27_1D0BC4(fn_27_1D0BC4_obj *p, u32 x)
{
    p->f = x;
}
