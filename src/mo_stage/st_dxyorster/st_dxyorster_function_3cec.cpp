#pragma force_active on
struct S {
    int a;
    int b;
    unsigned f : 5;
    unsigned g : 27;
};

extern "C" void fn_76_3CEC(S* s, unsigned v) {
    s->f = v;
}
