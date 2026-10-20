#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 5;
    u32 b : 5;
    u32 c : 22;
};

struct Outer {
    u32 pad[2];
    Bits bits;
};

extern "C" {
void fn_27_11B944(Outer *p, u32 v)
{
    p->bits.b = v;
}
}
