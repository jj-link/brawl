#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" {
void fn_27_19DDB8(S* s, u32 v)
{
    s->b = v;
}
}
