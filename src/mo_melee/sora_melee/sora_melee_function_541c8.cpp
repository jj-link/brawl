#include <types.h>
#pragma force_active on

struct Ret {
    u32 m0;
    u32 m1;
};

struct Inner {
    virtual void v0();
    virtual Ret* v1();
};

struct Outer {
    u32 m0;
    u32 m1;
    Inner* m_inner;
};

extern "C" {
u32 fn_27_541C8(Outer* p) {
    return p->m_inner->v1()->m1;
}
}
