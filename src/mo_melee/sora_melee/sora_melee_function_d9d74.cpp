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
};

class Outer {
public:
    u8 pad[0x10];
    Inner inner;
};

extern "C" {
void fn_27_D9D74(Outer* p) {
    p->inner.f3();
}
}
