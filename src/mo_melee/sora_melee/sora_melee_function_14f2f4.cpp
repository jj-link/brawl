#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a;
    u32 b;
    u32 hi : 14;
    u32 f : 7;
    u32 lo : 11;
};

extern "C" {
void fn_27_14F2F4(Bits* p, u32 v)
{
    p->f = v;
}
}
