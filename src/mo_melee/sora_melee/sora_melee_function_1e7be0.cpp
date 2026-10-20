#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad0;
    u32 pad4;
    u32 f0 : 2;
    u32 f1 : 2;
    u32 f2 : 28;
};

extern "C" {
void fn_27_1E7BE0(Bits *p, u32 v)
{
    p->f1 = v;
}
}
