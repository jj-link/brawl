#include <types.h>
#pragma force_active on

struct soInnerBase {
    virtual void vfunc0() = 0;
    virtual void vfunc1() = 0;
    virtual void vfunc2() = 0;
    virtual void vfunc3() = 0;
};

struct soOuterHolder {
    u32 unk0;
    u32 unk4;
    soInnerBase* m_inner;
};

extern "C" void fn_27_53194(soOuterHolder* p) {
    p->m_inner->vfunc1();
}
