#include <types.h>
#pragma force_active on

struct Ret {
    s32 m_pad;
    s32 m_val;
};

struct Inner {
    virtual void f0();
    virtual Ret* f1();
};

struct Outer {
    s32 m_pad[4];
    Inner m_inner;
};

extern "C" s32 fn_27_1E789C(Outer* self) {
    return self->m_inner.f1()->m_val;
}
