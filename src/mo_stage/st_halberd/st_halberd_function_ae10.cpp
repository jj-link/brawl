#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int pad : 6;
    unsigned int f : 3;
    unsigned int rest : 23;
};

extern "C" {
void fn_57_AE10(S* s, unsigned int v) {
    s->f = v;
}
}
