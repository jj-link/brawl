#pragma force_active on
struct S {
    int a;
    int b;
};

extern "C" void fn_54_5BDC(S* s) {
    s->b = -1;
    s->a = -1;
}
