#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 f : 4;
    u32 b : 24;
};

struct Outer {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_D2CAC(Outer* p, u32 v) {
    p->bits.f = v;
}
