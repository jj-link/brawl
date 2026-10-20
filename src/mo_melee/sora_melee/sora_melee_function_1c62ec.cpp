#include <types.h>
#pragma force_active on

class soSubVirtual {
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

class soOuterWork {
public:
    u8 m_pad[0x10];
    soSubVirtual m_sub;
};

extern "C" void fn_27_1C62EC(soOuterWork* self) {
    self->m_sub.f8();
}
