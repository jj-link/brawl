#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vfn0() = 0;
    virtual void vfn1() = 0;
    virtual void vfn2() = 0;
    virtual void vfn3() = 0;
    virtual void vfn4() = 0;
    virtual void vfn5() = 0;
};

class fn27Outer {
public:
    u8 pad[0x58];
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_45934(fn27Outer* p) {
    p->m_inner->vfn3();
}
}
