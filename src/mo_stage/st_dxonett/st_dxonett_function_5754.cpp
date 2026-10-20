#pragma force_active on
struct S {
    int pad0;
    int pad1;
    unsigned int a : 2;
    unsigned int b : 30;
};

extern "C" void fn_78_5754(S* s, unsigned int v) {
    s->a = v;
}
