#include <types.h>
#pragma force_active on

struct Ret {
    s32 m0;
    s32 m1;
};

struct Inner {
    virtual void f0();
    virtual Ret* f1();
    virtual void f2();
    virtual void f3();
};

struct Outer {
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_FAB08(Outer* self) {
    return self->m_inner.f1()->m1;
}
