#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 9;
    u32 lo : 23;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_CE68C(Obj* p, u32 v) {
    p->bits.hi = v;
}
