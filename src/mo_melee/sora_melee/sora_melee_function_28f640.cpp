#include <types.h>
#pragma force_active on

class soSubObj {
public:
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
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual u32 vfunc15(u32 a, u32 b);
    virtual void vfunc16();
    virtual void vfunc17();
};

class soOwner {
public:
    u8 m_pad[0xdb4];
    soSubObj m_sub;
};

extern "C" {
u32 fn_27_28F640(soOwner* this_, u32 a) {
    return this_->m_sub.vfunc15(a, 0);
}
}
