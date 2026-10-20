#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 4;
    u32 c : 24;
};

extern "C" {
void fn_27_199EA8(void *p, u32 v)
{
    Bits *x = (Bits *)((char *)p + 8);
    x->b = v;
}
}
