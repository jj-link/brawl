#pragma force_active on
struct S {
    int a;
    int b;
    unsigned int flags;
};

extern "C" void fn_79_56DC(S* s) {
    s->flags &= ~0x2000;
}
