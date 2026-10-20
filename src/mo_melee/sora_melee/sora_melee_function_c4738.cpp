#pragma force_active on
struct Sub {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct Outer {
    int pad[3];
    Sub sub;
};

extern "C" void fn_27_C4738(Outer* self) {
    self->sub.f4();
}
