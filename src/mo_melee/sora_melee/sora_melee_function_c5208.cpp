#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 pad : 2;
    u32 f : 2;
    u32 rest : 28;
};

extern "C" void fn_27_C5208(S* p, u32 v)
{
    p->f = v;
}
