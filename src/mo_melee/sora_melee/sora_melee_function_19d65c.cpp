#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 3;
    u32 rest : 29;
};

struct Outer {
    u32 pad[2];
    Bits b;
};

extern "C" void fn_27_19D65C(void *p, u32 v)
{
    ((Outer *)p)->b.hi = v;
}
