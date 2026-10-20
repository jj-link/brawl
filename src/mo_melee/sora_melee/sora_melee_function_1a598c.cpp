#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

extern "C" void fn_27_1A598C(void *p, u32 v)
{
    Bits *s = (Bits *)((char *)p + 8);
    s->f = v;
}
