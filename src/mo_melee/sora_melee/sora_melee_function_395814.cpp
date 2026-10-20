#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

extern "C" void fn_27_395814(void *self, u32 v)
{
    Bits *p = (Bits *)((char *)self + 8);
    p->f = v;
}
