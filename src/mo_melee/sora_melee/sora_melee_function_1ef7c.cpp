#include <types.h>
#pragma force_active on

class soSubObj {
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
    virtual void vf9();
    virtual void vf10();
};

struct soHolder {
    u32 m_0;
    soSubObj* m_obj;
    u32 m_8;
    u32 m_c;
};

extern "C" void fn_27_1EF7C(soHolder* self) {
    if (self->m_obj) {
        self->m_obj->vf8();
    }
    self->m_8 = 0;
    self->m_c = 0;
}
