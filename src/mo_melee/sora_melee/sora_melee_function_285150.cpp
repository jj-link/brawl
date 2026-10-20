#include <types.h>
#pragma force_active on

class fn27Sub {
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
};

class fn27Outer {
public:
    u8 m_pad[0x27fc];
    fn27Sub m_sub;
};

extern "C" void fn_27_285150(fn27Outer* p) {
    p->m_sub.vfunc8();
}
