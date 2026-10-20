#include <types.h>
#pragma force_active on

struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Other {
    u32 pad[4];
};

struct Derived : public Other, public Base {
    virtual void f3();
};

extern "C" void fn_27_D9DB4(Derived& self) {
    static_cast<Base&>(self).f3();
}
