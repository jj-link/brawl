#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Obj {
    int a, b, c;
    Base base;
};

extern "C" void fn_27_1A9C74(Obj* p) {
    p->base.f4();
}
