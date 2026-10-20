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
};

class Outer {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    Inner m_c;
};

extern "C" void fn_27_1A9420(Outer* o) {
    o->m_c.f4();
}
