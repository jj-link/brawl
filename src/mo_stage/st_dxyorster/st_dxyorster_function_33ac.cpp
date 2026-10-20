#pragma force_active on
struct S {
    int a;
    int b;
};

extern "C" void fn_76_33AC(S* s) {
    s->b = -1;
    s->a = -1;
}
