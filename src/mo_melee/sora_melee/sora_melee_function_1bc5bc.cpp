#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_1BC5BC(Outer* p) {
    p->m_inner.f1();
}
