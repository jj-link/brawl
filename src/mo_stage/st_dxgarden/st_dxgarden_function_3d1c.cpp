#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f : 4;
};

extern "C" void fn_77_3D1C(S* s, int v) {
    s->f = v;
}
