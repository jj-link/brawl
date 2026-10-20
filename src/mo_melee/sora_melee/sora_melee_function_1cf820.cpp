#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

extern "C" void fn_27_1CF820(u32* p, u32 v)
{
    ((Bits*)&p[2])->f = v;
}
