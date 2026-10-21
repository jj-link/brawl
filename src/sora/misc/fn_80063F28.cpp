#pragma force_active on
struct S {
    char pad[0x5b];
    char b5B;
};

extern "C" void fn_80063F28(struct S* s, unsigned int n) {
    int v = 1;
    if (n > 1) {
        v = n;
    }
    s->b5B = v;
}
