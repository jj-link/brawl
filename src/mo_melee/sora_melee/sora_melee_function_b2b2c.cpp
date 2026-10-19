#include <types.h>
#pragma force_active on

class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class soHolder {
public:
    u8 pad[0x18];
    soBase* m_base;
};

extern "C" void fn_27_B1C68();

extern "C" {
void fn_27_B2B2C(soHolder* p) {
    p->m_base->vf1();
    fn_27_B1C68();
}
}
