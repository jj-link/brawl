#pragma force_active on
extern "C" {
struct Bits {
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
};
struct Obj {
    unsigned int w0;
    unsigned int w1;
    Bits bits;
};
void fn_40_24B44(Obj* p, unsigned int v) {
    p->bits.f = v;
}
}
