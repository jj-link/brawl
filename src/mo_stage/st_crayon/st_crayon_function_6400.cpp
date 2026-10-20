#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int f : 2;
};

extern "C" void fn_56_6400(S* s, int v) {
    s->f = v;
}
