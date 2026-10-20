#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" void fn_27_122A70(S* p, u32 v)
{
    p->hi = v;
}
