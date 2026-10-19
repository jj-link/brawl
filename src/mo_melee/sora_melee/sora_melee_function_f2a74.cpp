#include <types.h>
#pragma force_active on

struct Target {
    u32 m_pad;
    u32 m_val;
};

struct Inner {
    virtual void v0();
    virtual Target* v1();
    virtual void v2();
    virtual void v3();
};

struct Outer {
    u8 m_pad[0x10];
    Inner m_inner;
};

extern "C" u32 fn_27_F2A74(Outer* p) {
    return p->m_inner.v1()->m_val;
}
