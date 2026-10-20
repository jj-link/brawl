#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

extern "C" void fn_27_122B0C(void *p, u32 v)
{
    Bits *w = (Bits *)((char *)p + 8);
    w->f = v;
}
