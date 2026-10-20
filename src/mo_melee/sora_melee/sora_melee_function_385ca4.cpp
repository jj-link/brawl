#pragma force_active on
struct FnBits {
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
};

struct FnObj {
    unsigned int w0;
    unsigned int w1;
    FnBits bits;
};

extern "C" void fn_27_385CA4(FnObj* p, unsigned int v) {
    p->bits.b = v;
}
