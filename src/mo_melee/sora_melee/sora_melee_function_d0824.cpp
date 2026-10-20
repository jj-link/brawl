#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 7;
    u32 b : 7;
    u32 c : 18;
};

extern "C" {
void fn_27_D0824(S *p, u32 v)
{
    p->b = v;
}
}
