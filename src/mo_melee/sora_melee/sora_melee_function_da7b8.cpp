#include <types.h>
#pragma force_active on

struct Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Outer {
    u8 pad[8];
    Inner* m_inner;
};

extern "C" void fn_27_DA7B8(Outer* p) {
    p->m_inner->vf4();
}
