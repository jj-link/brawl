#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 pad0 : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" void fn_27_1A1010(S* p, u32 v)
{
    p->f = v;
}
