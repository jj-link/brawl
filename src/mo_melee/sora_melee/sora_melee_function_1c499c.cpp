#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual Inner* v1();
    virtual void v2();
    virtual void v3();
    s32 m_val;
};

struct Outer {
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_1C499C(Outer* p) {
    return p->m_inner.v1()->m_val;
}
