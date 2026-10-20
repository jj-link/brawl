#include <types.h>
#pragma force_active on

class soInnerBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class soOuter {
public:
    u32 m_pad[3];
    soInnerBase m_inner;
};

extern "C" {
void fn_27_D5FA8(soOuter* self) {
    soInnerBase* p = &self->m_inner;
    p->f4();
}
}
