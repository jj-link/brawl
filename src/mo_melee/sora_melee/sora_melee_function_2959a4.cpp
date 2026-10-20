#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 w0;
    u32 w1;
    u32 pad : 4;
    u32 val : 4;
    u32 rest : 24;
};

extern "C" {
void fn_27_2959A4(S *p, u32 v)
{
    p->val = v;
}
}
