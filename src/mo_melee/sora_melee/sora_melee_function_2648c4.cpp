#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 a : 2;
    u32 b : 2;
    u32 c : 28;
};

extern "C" void fn_27_2648C4(Bits *p, u32 v)
{
    p->b = v;
}
