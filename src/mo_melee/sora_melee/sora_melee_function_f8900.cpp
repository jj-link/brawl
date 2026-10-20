#include <types.h>
#pragma force_active on

class fnInner {
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
};

class fnOuter {
public:
    u32 unk0[4];
    fnInner m_inner;
};

extern "C" void fn_27_F8900(fnOuter* p) {
    p->m_inner.f8();
}
