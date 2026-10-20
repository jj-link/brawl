#include <types.h>
#pragma force_active on

struct B {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u32 pad[4];
    B b;
};

extern "C" void fn_27_38FBA0(Outer* p) {
    p->b.f1();
}
