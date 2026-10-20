#include <types.h>
#pragma force_active on

class soInnerVirt {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class soOuterHolder {
public:
    u8 pad[0x20];
    soInnerVirt* m_inner;
};

extern "C" {
void fn_27_72C2C(soOuterHolder* holder) {
    holder->m_inner->vf4();
}
}
