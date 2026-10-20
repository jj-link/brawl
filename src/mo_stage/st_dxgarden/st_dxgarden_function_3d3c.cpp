#pragma force_active on
struct S {
    int a;
    int b;
    unsigned pad : 4;
    unsigned f : 4;
    unsigned rest : 24;
};

extern "C" void fn_77_3D3C(S* s, unsigned v) {
    s->f = v;
}
