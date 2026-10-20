#include <types.h>
#pragma force_active on

struct A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct B {
    u32 pad[4];
};

struct C : B, A {
};

extern "C" {
void fn_27_1C3C6C(C* p) {
    A& a = *p;
    a.f1();
}
}
