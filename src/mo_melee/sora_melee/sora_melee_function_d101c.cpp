#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 b : 8;
    u32 c : 16;
};

struct Outer {
    u32 pad0;
    u32 pad1;
    Bits w;
};

extern "C" void fn_27_D101C(Outer *p, u32 v)
{
    p->w.b = v;
}
