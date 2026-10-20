#include <types.h>
#pragma force_active on

class IFoo {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    u8 pad[0x10];
    IFoo m_foo;
};

extern "C" void fn_27_1E7540(Outer* self) {
    self->m_foo.f1();
}
