#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" {
void fn_48_BB78(S *s, u32 v)
{
    s->hi = v;
}
}
