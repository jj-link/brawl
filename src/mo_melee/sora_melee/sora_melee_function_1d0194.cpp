#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 unk0;
    u32 unk4;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_1D0194(S *p, u32 v)
{
    p->hi = v;
}
