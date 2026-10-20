#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 20;
    u32 f : 10;
    u32 b : 2;
};

struct S {
    u32 pad[2];
    Bits w;
};

extern "C" {
void fn_27_385BA0(S *p, u32 v)
{
    p->w.f = v;
}
}
