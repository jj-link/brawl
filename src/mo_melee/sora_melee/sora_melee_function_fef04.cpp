#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 pad[2];
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" void fn_27_FEF04(S *p, u32 v)
{
    p->b = v;
}
