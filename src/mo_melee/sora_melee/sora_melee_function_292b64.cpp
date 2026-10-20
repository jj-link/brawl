#include <types.h>
#pragma force_active on

struct fn_27_292B64_Foo {
    s32 m_0;
    s32 m_4;
};

class fn_27_292B64_Inner {
public:
    virtual void v0();
    virtual fn_27_292B64_Foo* v1();
};

class fn_27_292B64_Outer {
public:
    s32 m_0;
    s32 m_4;
    s32 m_8;
    s32 m_c;
    fn_27_292B64_Inner m_inner;
};

extern "C" {
s32 fn_27_292B64(fn_27_292B64_Outer* self) {
    return self->m_inner.v1()->m_4;
}
}
