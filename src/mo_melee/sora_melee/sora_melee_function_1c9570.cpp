#include <types.h>
#pragma force_active on

class soSubBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class fnOuter {
public:
    u8 pad[0x10];
    soSubBase m_sub;
};

extern "C" void fn_27_1C9570(fnOuter* self) {
    self->m_sub.f1();
}
