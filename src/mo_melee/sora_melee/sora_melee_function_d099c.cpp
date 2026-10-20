#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 b : 7;
    u32 a : 25;
};

extern "C" void fn_27_D099C(Bits *p, u32 v)
{
    p->b = v;
}
