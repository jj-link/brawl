#include <types.h>
#pragma force_active on

class soFnBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
};

class soFnOwner {
public:
    u8 pad[0x44];
    soFnBase* m_obj;
};

extern "C" {
void fn_27_2E300(soFnOwner* self) {
    self->m_obj->vf2();
}
}
