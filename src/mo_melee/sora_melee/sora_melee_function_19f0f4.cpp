#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_19F0F4(u32 *p, u32 v);
}

struct Bits {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};

void fn_27_19F0F4(u32 *p, u32 v)
{
    Bits *s = (Bits *)&p[2];
    s->b = v;
}
