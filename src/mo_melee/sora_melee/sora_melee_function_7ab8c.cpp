#pragma force_active on
struct FnBits {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

struct FnObj {
    unsigned int w0;
    unsigned int w1;
    FnBits w2;
};

extern "C" void fn_27_7AB8C(FnObj *p, unsigned int v) {
    p->w2.b = v;
}
