#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

extern "C" void fn_27_1A0A20(void *p, u32 x)
{
    struct Bits *s = (struct Bits *)((char *)p + 8);
    s->f = x;
}
