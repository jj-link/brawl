#pragma force_active on
struct S {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 28;
};

extern "C" void fn_73_AA10(S *p, unsigned int v) {
    p->a = v;
}
