#pragma force_active on
struct Obj {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
};

extern "C" void fn_40_1E6E0(Obj* p, unsigned int v) {
    p->b = v;
}
