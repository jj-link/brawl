#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" void fn_27_199384(S *p, u32 v)
{
    p->b = v;
}
