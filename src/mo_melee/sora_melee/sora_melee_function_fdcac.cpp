#include <types.h>
#pragma force_active on

class Base1 {
public:
    virtual void g();
    u32 a;
    u32 b;
    u32 c;
};

class Iface {
public:
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
    virtual void f13();
    virtual void f14();
    virtual void f15();
};

class Derived : public Base1, public Iface {
};

extern "C" void fn_27_FDCAC(Derived* self) {
    static_cast<Iface&>(*self).f13();
}
