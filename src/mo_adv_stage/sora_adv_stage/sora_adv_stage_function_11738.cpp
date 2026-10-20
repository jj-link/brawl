#pragma force_active on
struct S {
    int a;
    int b;
    unsigned pad : 10;
    unsigned f : 5;
    unsigned rest : 17;
};

extern "C" void fn_40_11738(S* s, unsigned v) {
    s->f = v;
}
