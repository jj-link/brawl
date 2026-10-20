#include <types.h>
#pragma force_active on

struct soVirtualInner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
};

struct soVirtualOuter {
    u8 pad[0x14];
    soVirtualInner* m_inner;
};

extern "C" {
void fn_27_871E8(soVirtualOuter* p) {
    p->m_inner->vfunc9();
}
}
