#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 w0;
    u32 w1;
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

extern "C" {
void fn_27_1A24B0(Bits* p, u32 v)
{
    p->f = v;
}
}
