#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 18;
    u32 b : 9;
    u32 c : 5;
};

extern "C" void fn_48_B57C(S *s, u32 v)
{
    s->b = v;
}
