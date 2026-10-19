#include <types.h>
#pragma force_active on

struct fn27Inner {
    virtual void vf0();
    virtual fn27Inner* vf1();
    virtual void vf2();
    s32 m_value;
};

struct fn27Outer {
    u8 m_pad[0x10];
    fn27Inner m_inner;
};

extern "C" {
s32 fn_27_FC8B4(fn27Outer* p) {
    return p->m_inner.vf1()->m_value;
}
}
