#include <types.h>
#pragma force_active on

class SubObj {
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
};

class OwnerObj {
public:
    u32 m_pad[12];
    SubObj m_sub;
};

extern "C" void fn_27_1510C8(OwnerObj* self) {
    self->m_sub.f7();
}
