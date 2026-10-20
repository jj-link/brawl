#pragma force_active on
struct Bits {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};

struct Obj {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_198514(Obj *p, unsigned int v) {
    p->bits.b = v;
}
