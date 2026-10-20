#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" {
void fn_74_6AD8(void *p, u32 v)
{
    struct Bits *w = (struct Bits *)((char *)p + 8);
    w->b = v;
}
}
