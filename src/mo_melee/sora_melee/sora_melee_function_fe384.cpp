#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

struct Obj {
    u32 pad0;
    u32 pad1;
    Bits bits;
};

extern "C" void fn_27_FE384(Obj *p, u32 v) {
    p->bits.b = v;
}
