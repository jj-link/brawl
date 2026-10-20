#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

struct Obj {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" void fn_27_1CFE98(Obj* p, u32 v)
{
    p->bits.f = v;
}
