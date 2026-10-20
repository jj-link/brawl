#pragma force_active on
typedef unsigned int u32;

struct BitField6 {
    u32 a : 6;
    u32 b : 26;
};

struct Holder {
    u32 pad[2];
    BitField6 bits;
};

extern "C" void fn_27_7AB6C(Holder* p, u32 v) {
    p->bits.a = v;
}
