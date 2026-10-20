#pragma force_active on
struct FnState {
    int a;
    int b;
    unsigned int hi : 2;
    unsigned int rest : 30;
};

extern "C" void fn_51_64CC(FnState *p, unsigned int v) {
    p->hi = v;
}
