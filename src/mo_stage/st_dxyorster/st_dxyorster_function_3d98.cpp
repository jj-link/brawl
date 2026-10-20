#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int x : 10;
    unsigned int f : 5;
    unsigned int y : 17;
};

extern "C" void fn_76_3D98(S* s, int v) {
    s->f = v;
}
