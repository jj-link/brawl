#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a : 3;
    u32 f : 3;
    u32 b : 26;
};

extern "C" void fn_27_CF9CC(S *p, u32 v)
{
    p[2].f = v;
}
