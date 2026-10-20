#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a;
    u32 b;
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" void fn_27_19AEDC(S* s, u32 v)
{
    s->f = v;
}
