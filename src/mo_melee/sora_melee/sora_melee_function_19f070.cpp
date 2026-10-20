#pragma force_active on
struct Obj {
    unsigned int w0;
    unsigned int w1;
    unsigned int f : 3;
    unsigned int rest : 29;
};

extern "C" {
void fn_27_19F070(Obj* p, unsigned int v) {
    p->f = v;
}
}
