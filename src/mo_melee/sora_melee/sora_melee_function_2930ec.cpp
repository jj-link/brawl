#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

struct Outer {
    int a, b, c, d;
    Base base;
};

extern "C" void fn_27_2930EC(Outer* self) {
    self->base.f8();
}
