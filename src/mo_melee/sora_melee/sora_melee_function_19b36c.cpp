#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 w0;
    u32 w1;
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

extern "C" {
void fn_27_19B36C(Bits* p, u32 v) {
    p->b = v;
}
}
