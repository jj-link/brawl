#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 3;
    u32 b : 29;
};

extern "C" {
void fn_27_19CD3C(u32 *p, u32 v)
{
    Bits *bp = (Bits *)&p[2];
    bp->a = v;
}
}
