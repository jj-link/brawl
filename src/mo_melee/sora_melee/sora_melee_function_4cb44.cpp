#pragma force_active on
typedef unsigned int u32;

struct Fn27Bits {
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_4CB44(void *p, u32 v)
{
    Fn27Bits *w = (Fn27Bits *)((char *)p + 8);
    w->b = v;
}
