#pragma force_active on
struct Bits {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

struct Obj {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_72DEC(Obj* p, unsigned int v) {
    p->bits.b = v;
}
