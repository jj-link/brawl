#pragma force_active on
struct FnBits27 {
    unsigned int a : 3;
    unsigned int b : 29;
};

struct FnHolder27 {
    int pad[2];
    FnBits27 bits;
};

extern "C" {
void fn_27_1A01F8(FnHolder27 *p, unsigned int v) {
    p->bits.a = v;
}
}
