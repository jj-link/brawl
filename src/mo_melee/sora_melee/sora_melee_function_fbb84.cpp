#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Outer {
public:
    u32 m_pad[4];
    Inner m_inner;
};

extern "C" void fn_27_FBB84(Outer* p) {
    return p->m_inner.f1();
}
