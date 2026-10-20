#include <types.h>
#pragma force_active on

class emSubObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

class emHolder {
public:
    u8 _pad[0x2c];
    emSubObj* m_sub;
};

extern "C" {
void fn_41_2B3D0(emHolder* p) {
    return p->m_sub->vf6();
}
}
