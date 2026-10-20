#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Outer {
    u8 pad[0x2c];
    Inner* m_inner;
};

extern "C" void fn_27_75DA0(Outer* p) {
    p->m_inner->f3();
}
