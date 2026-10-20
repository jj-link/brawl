#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 f : 4;
    u32 b : 20;
};

extern "C" void fn_27_1E7F8C(u32* p, u32 v) {
    Bits* s = (Bits*)(p + 2);
    s->f = v;
}
