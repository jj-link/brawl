#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" void fn_27_1D0AD0(S* p, u32 v)
{
    p->f = v;
}
