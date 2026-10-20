#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 pad[2];
    u32 a : 14;
    u32 b : 7;
    u32 c : 11;
};

extern "C" void fn_27_FECDC(Bits *p, u32 v)
{
    p->b = v;
}
