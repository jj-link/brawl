#include <types.h>
#pragma force_active on

class soSubObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class soOuterObject {
public:
    u8 m_pad[0xc];
    soSubObject m_sub;
};

extern "C" {
void fn_27_1AAF44(soOuterObject* self) {
    self->m_sub.vf4();
}
}
