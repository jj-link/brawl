#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" {
void fn_27_FE5E8(S* s, u32 v)
{
    s->b = v;
}
}
