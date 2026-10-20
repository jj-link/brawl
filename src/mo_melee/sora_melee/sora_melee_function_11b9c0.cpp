#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 10;
    u32 f : 5;
    u32 b : 17;
};

struct Obj {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" void fn_27_11B9C0(Obj *p, u32 v) {
    p->bits.f = v;
}
