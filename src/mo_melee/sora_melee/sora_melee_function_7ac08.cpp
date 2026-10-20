#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 12;
    u32 f : 6;
    u32 b : 14;
};

extern "C" void fn_27_7AC08(u32 *p, u32 v)
{
    ((Bits *)&p[2])->f = v;
}
