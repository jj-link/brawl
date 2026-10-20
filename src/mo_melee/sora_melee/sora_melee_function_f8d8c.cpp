#include <types.h>
#pragma force_active on

class fnSubAbstract {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual s32 f15();
};

class fnOuter {
public:
    u8 m_pad[0x10];
    fnSubAbstract m_sub;
};

extern "C" {
s32 fn_27_F8D8C(fnOuter* self) {
    return self->m_sub.f15();
}
}
