#pragma force_active on
struct Base { char pad[0x3c]; };
#define R10(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();
struct Inner : Base {
    R10(a) R10(b) R10(c) R10(d) R10(e) R10(g) R10(h) R10(i) R10(j)
    virtual void target();
};
struct A {
    char pad[0x70];
    Inner* inner;
};
struct B {
    char pad[0x74];
    unsigned int flags;
};

extern "C" void fn_27_2636B4(A* a, int, B* b) {
    if (!((b->flags >> 5) & 1)) {
        a->inner->target();
    }
}
