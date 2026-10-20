#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_C9DD8(S *p, u32 v)
{
    p->b = v;
}
