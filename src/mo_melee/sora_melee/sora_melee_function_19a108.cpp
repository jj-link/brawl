#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 5;
    u32 b : 27;
};

extern "C" {
void fn_27_19A108(void *p, u32 v)
{
    Bits *w = (Bits *)((char *)p + 8);
    w->a = v;
}
}
