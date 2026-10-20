#include <types.h>
#pragma force_active on

struct Inner {
    virtual void vf0();
    virtual Inner* vf1();
    virtual void vf2();
    virtual void vf3();
    s32 m_val;
};

struct Outer {
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_1BE6B4(Outer* p) {
    Inner* r = p->m_inner.vf1();
    return r->m_val;
}
