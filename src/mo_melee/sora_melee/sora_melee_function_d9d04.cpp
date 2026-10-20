#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Outer {
    u32 m_0[4];
    Inner m_10;
};

extern "C" void fn_27_D9D04(Outer* self) {
    Inner* p = &self->m_10;
    p->f3();
}
