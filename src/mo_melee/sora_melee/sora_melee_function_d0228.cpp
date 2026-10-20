#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 hi : 14;
    u32 f : 7;
    u32 lo : 11;
};

extern "C" {
void fn_27_D0228(u32* p, u32 v) {
    Bits* b = (Bits*)(p + 2);
    b->f = v;
}
}
