#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
};

class Outer {
public:
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" void fn_27_2BB5E8(Outer* p) {
    p->m_inner.f1();
}
