#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class fn27Outer {
public:
    u8 pad[0xc];
    fn27Inner m_inner;
};

extern "C" void fn_27_38F810(fn27Outer* p) {
    p->m_inner.f4();
}
