#pragma force_active on
struct Obj {
    int w0;
    int w1;
    unsigned int : 4;
    unsigned int f : 4;
    unsigned int : 24;
};

extern "C" void fn_27_D3278(Obj* p, unsigned int v) {
    p->f = v;
}
