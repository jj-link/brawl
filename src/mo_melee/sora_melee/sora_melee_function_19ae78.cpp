#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 5;
    u32 mid : 5;
    u32 lo : 22;
};

extern "C" void fn_27_19AE78(u32 *p, u32 v)
{
    ((Bits *)&p[2])->mid = v;
}
