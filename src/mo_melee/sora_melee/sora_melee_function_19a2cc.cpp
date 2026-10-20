#pragma force_active on
struct Bits {
    unsigned int hi : 10;
    unsigned int f : 5;
    unsigned int lo : 17;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    Bits w2;
};

extern "C" void fn_27_19A2CC(Obj *p, unsigned int v) {
    p->w2.f = v;
}
