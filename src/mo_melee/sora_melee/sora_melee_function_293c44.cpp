#include <types.h>
#pragma force_active on

class soInnerWork {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuterWork {
public:
    u32 pad[4];
    soInnerWork m_inner;
};

extern "C" {
void fn_27_293C44(soOuterWork* self) {
    soInnerWork* p = &self->m_inner;
    p->vf3();
}
}
