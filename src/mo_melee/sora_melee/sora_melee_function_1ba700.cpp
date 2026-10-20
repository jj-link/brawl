#include <types.h>
#pragma force_active on

class fn27Sub {
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

class fn27Outer {
public:
    u32 m_unk0;
    u32 m_unk4;
    u32 m_unk8;
    u32 m_unkC;
    fn27Sub m_sub;
};

extern "C" void fn_27_1BA700(fn27Outer* self) {
    self->m_sub.f8();
}
