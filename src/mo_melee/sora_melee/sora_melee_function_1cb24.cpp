#include <types.h>
#pragma force_active on

class soInnerObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class soOuterObj {
public:
    u8 m_pad[0x34];
    soInnerObj* m_inner;
};

extern "C" void fn_27_1CB24(soOuterObj* p) {
    p->m_inner->f3();
}
