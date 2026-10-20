#pragma force_active on
struct S {
    int a0;
    int a4;
    int a8;
    int ac;
    int a10;
};

extern "C" void fn_110_12CAC(S* s, int v) {
    s->a10 = v;
    s->ac = v;
    s->a8 = v;
}
