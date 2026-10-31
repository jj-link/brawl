#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

class soHolder {
public:
    u8 m_pad[0x54];
    soVirtBase* m_obj;
};

extern "C" {
void fn_27_24808C(soHolder* self) {
    if (self->m_obj) {
        self->m_obj->vf5();
    }
}
}
