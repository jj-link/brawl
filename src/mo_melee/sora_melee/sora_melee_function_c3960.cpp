#pragma force_active on
struct A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct B {
    char pad[12];
    A* p;
};

extern "C" void fn_27_C3960(B* self) {
    self->p->f3();
}
