#include <types.h>
#pragma force_active on

class soInner {
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

class soOuter {
public:
    u8 pad[0x10];
    soInner m_inner;
};

extern "C" void fn_27_1BB570(soOuter* p) {
    p->m_inner.f13();
}
