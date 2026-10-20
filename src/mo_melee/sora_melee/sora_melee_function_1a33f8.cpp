#pragma force_active on
typedef unsigned int u32;

struct S {
    char pad[8];
    u32 hi : 20;
    u32 f : 10;
    u32 lo : 2;
};

extern "C" {
void fn_27_1A33F8(S* s, u32 v)
{
    s->f = v;
}
}
