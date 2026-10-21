#pragma force_active on
struct S {
    unsigned char pad[0x188];
    int a;
};

extern "C" void fn_8009D2B0(S* p) {
    if (p->a > 0) {
        p->a = p->a - 1;
    }
}
