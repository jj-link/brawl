#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 5;
    u32 lo : 27;
};

extern "C" {
void fn_27_1A2490(u32 *p, u32 v)
{
    ((Bits *)(p + 2))->hi = v;
}
}
