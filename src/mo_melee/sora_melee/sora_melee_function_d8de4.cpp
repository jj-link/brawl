#include <types.h>
#pragma force_active on

struct Base {
    virtual void b0(void);
    u32 pad[3];
};

struct Iface {
    virtual void f0(void);
    virtual void f1(void);
    virtual void f2(void);
    virtual void f3(void);
    virtual void f4(void);
    virtual void f5(void);
    virtual void f6(void);
    virtual void f7(void);
    virtual void f8(void);
    virtual void f9(void);
    virtual void f10(void);
    virtual void f11(void);
    virtual void f12(void);
    virtual void f13(void);
    virtual void f14(void);
    virtual void f15(void);
};

struct Derived : Base, Iface {
};

extern "C" void fn_27_D8DE4(Derived& self) {
    Iface& p = self;
    p.f13();
}
