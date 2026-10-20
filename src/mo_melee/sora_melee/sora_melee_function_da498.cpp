#include <types.h>
#pragma force_active on

class soInnerBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct soOuterObj {
    u32 unk0;
    u32 unk4;
    soInnerBase* m_inner;
};

extern "C" void fn_27_DA498(soOuterObj* self) {
    self->m_inner->vf4();
}
