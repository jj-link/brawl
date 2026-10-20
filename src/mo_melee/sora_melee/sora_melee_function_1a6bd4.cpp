#pragma force_active on
typedef unsigned long u32;

struct S {
    u32 w0;
    u32 w1;
    struct {
        u32 hi : 20;
        u32 f : 10;
        u32 lo : 2;
    } bf;
};

extern "C" void fn_27_1A6BD4(S *p, u32 v)
{
    p->bf.f = v;
}
