#pragma force_active on
struct Bits {
    unsigned int a : 8;
    unsigned int b : 8;
    unsigned int c : 16;
};

struct Obj {
    unsigned int pad[2];
    Bits bits;
};

extern "C" void fn_27_CB368(Obj* p, unsigned int v) {
    p->bits.b = v;
}
