#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 6;
    u32 f : 3;
    u32 b : 23;
};

extern "C" {
void fn_27_2EB9AC(char* p, u32 v) {
    Bits* s = (Bits*)(p + 8);
    s->f = v;
}
}
