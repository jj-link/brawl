#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 hi : 10;
    u32 f : 10;
    u32 lo : 12;
};

extern "C" {
void fn_27_1A3394(S* s, u32 v)
{
    s->f = v;
}
}
