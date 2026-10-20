#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 hi : 3;
    u32 a : 3;
    u32 rest : 26;
};

extern "C" void fn_27_CC6E8(S *p, u32 v)
{
    p->a = v;
}
