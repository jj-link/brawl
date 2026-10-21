#pragma force_active on

struct S {
    int pad[2];
    unsigned int b : 5;
    unsigned int a : 27;
};

extern "C" void fn_76_3E7C(S* s, unsigned int v) {
    s->b = v;
}
