#include <types.h>
#pragma force_active on

struct fn27Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct fn27Outer {
    u8 pad0[8];
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_DA678(fn27Outer* p) {
    p->m_inner->vf4();
}
}
