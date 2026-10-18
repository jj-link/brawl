#pragma force_active on
struct X {
    char pad[0x15c];
    void* a;
    void* b;
};

extern "C" {
void fn_27_166FC(X* x, void* a, void* b) {
    x->a = a;
    x->b = b;
}
}
