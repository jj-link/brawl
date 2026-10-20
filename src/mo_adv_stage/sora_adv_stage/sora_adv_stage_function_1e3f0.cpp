#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

struct Obj {
    u32 w0;
    u32 w1;
    Bits bits;
};

extern "C" {
void fn_40_1E3F0(Obj* p, u32 v) {
    p->bits.f = v;
}
}
