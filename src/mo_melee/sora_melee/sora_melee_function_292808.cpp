#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Sub {
    int a, b, c, d;
    Base base;
};

extern "C" void fn_27_292808(Sub* p) {
    p->base.f1();
}
