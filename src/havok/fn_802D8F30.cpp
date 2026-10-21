#pragma force_active on
struct Sub {
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
    virtual void f11();
    virtual void f12();
};

struct Outer {
    char pad[0x10];
    Sub sub;
};

extern "C" {
void fn_802D8F30(Outer* self) {
    self->sub.f10();
}
}
