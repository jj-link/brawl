#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad1;
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" void fn_27_2EBA74(Bits *p, u32 v)
{
    p->b = v;
}
