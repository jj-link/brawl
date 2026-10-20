#pragma force_active on
struct S {
    int a;
    int b;
    unsigned f : 2;
    unsigned g : 30;
};

extern "C" void fn_54_6514(S* s, unsigned v) {
    s->f = v;
}
