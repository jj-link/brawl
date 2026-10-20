#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 w0;
    u32 w1;
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

extern "C" void fn_27_1A29E0(Bits* p, u32 v)
{
    p->f = v;
}
