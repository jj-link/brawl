#include <types.h>
#pragma force_active on

class soSubObj {
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

class soOuterObj {
public:
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    soSubObj m_sub;
};

extern "C" void fn_27_1CCFB8(soOuterObj* p) {
    p->m_sub.f8();
}
