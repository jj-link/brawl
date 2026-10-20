#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

struct Obj {
    char pad[44];
    Base* base;
};

extern "C" void fn_27_3BA50(Obj* self) {
    self->base->f4();
}
