#include <types.h>
#pragma force_active on

class Inner {
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
};

class Outer {
public:
    u8 pad[0x30];
    Inner inner;
};

extern "C" void fn_27_1510A8(Outer* p) {
    p->inner.f9();
}
