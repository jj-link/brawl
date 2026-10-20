#include <types.h>
#pragma force_active on

struct fn27Inner;

struct fn27Inner {
    virtual void f0();
    virtual fn27Inner* f1();
    virtual void f2();
    virtual void f3();
    s32 m_field;
};

struct fn27Outer {
    u32 m_pad[4];
    fn27Inner m_inner;
};

extern "C" s32 fn_27_1C0460(fn27Outer* self) {
    return self->m_inner.f1()->m_field;
}
