#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 10;
    u32 f : 5;
    u32 lo : 17;
};

struct Obj {
    u32 pad0;
    u32 pad4;
    Bits bits;
};

extern "C" void fn_27_199C8C(Obj* p, u32 v)
{
    p->bits.f = v;
}
