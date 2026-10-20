#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 a : 10;
    u32 f : 5;
    u32 g : 5;
    u32 b : 12;
};

struct T {
    u32 w0;
    u32 w1;
    S s;
};

extern "C" void fn_27_2957BC(T *p, u32 v)
{
    p->s.f = v;
}
