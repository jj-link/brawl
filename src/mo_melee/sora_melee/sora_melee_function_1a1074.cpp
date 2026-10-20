#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" void fn_27_1A1074(u32 *p, u32 v)
{
    ((Bits *)&p[2])->b = v;
}
