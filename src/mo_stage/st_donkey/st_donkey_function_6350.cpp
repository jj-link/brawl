#pragma force_active on
struct S {
    int a;
    int b;
    unsigned f : 2;
    unsigned g : 30;
};

extern "C" void fn_50_6350(S* s, int v) {
    s->f = v;
}
