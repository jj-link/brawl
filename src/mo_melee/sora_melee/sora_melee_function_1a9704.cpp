#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class Outer {
public:
    u32 m_pad[3];
    Sub m_sub;
};

extern "C" void fn_27_1A9704(Outer* self) {
    self->m_sub.f4();
}
