#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a;
    u32 b;
    u32 x : 12;
    u32 y : 6;
    u32 z : 14;
};

extern "C" {
void fn_27_CF3D0(Bits *p, u32 v)
{
    p->y = v;
}
}
