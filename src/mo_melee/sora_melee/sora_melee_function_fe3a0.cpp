#pragma force_active on
struct Obj {
    int a;
    int b;
    unsigned int hi : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_FE3A0(Obj* p, unsigned int v) {
    p->hi = v;
}
