#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class Outer {
public:
    u32 m_pad[3];
    Inner m_inner;
};

extern "C" {
void fn_27_1AB95C(Outer* self);
}

extern "C" void fn_27_1AB95C(Outer* self) {
    self->m_inner.v4();
}
