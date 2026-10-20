#include <types.h>
#pragma force_active on

struct Inner {
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
};

struct Outer {
    u32 pad[4];
    Inner m_inner;
};

extern "C" void fn_27_1BC4AC(Outer* self) {
    self->m_inner.f8();
}
