#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 20;
    u32 f : 10;
    u32 lo : 2;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_1A494C(Obj* p, u32 v)
{
    p->bits.f = v;
}
