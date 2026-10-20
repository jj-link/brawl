#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 20;
    u32 f : 10;
    u32 b : 2;
};

extern "C" void fn_27_1A6EE0(u32 *p, u32 v)
{
    ((Bits *)&p[2])->f = v;
}
