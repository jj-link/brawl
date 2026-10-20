#pragma force_active on
struct SoBlocks {
    void* a;
    void* b;
    void* c;
};

extern "C" void __dla__FPv(void*);

extern "C" void fn_27_239F6C(SoBlocks* p) {
    if (p->a) {
        __dla__FPv(p->a);
    }
    if (p->b) {
        __dla__FPv(p->b);
    }
    if (p->c) {
        __dla__FPv(p->c);
    }
    p->a = 0;
    p->b = 0;
    p->c = 0;
}
