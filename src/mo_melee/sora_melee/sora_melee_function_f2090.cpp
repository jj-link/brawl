#include <types.h>
#pragma force_active on

struct Res {
    u32 m_0;
    u32 m_4;
};

struct Sub {
    virtual void vf0();
    virtual Res* vf1();
};

struct Outer {
    u8 m_pad[0x10];
    Sub m_sub;
};

extern "C" u32 fn_27_F2090(Outer* p) {
    return p->m_sub.vf1()->m_4;
}
