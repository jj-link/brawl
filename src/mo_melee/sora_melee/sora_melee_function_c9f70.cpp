#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 a : 3;
    u32 f : 3;
    u32 b : 26;
};

extern "C" void fn_27_C9F70(S *s, u32 v)
{
    s->f = v;
}
