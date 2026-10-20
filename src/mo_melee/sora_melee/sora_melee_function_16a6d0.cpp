#include <types.h>
#pragma force_active on

class fn_27_Inner {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
};

class fn_27_Outer {
public:
    u32 unk0;
    fn_27_Inner* m_inner;
};

extern "C" void fn_27_16A6D0(fn_27_Outer* p) {
    p->m_inner->vf1();
}
