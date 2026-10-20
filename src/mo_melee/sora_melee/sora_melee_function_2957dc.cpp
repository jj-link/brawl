#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 6;
    u32 mid : 6;
    u32 lo : 20;
};

extern "C" void fn_27_2957DC(u32 *p, u32 v)
{
    Bits *b = (Bits *)(p + 2);
    b->mid = v;
}
