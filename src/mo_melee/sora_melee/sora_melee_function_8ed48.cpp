#include <types.h>
#pragma force_active on

class soSubObj {
public:
    virtual ~soSubObj();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(s16 value);
};

class soOwner {
public:
    s32 m_pad[3];
    soSubObj* m_sub;
};

extern "C" void fn_27_8ED48(soOwner* self, s16 value) {
    self->m_sub->vf5(value);
}
