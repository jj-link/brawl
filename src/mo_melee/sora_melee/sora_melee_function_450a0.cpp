#include <types.h>
#pragma force_active on

class soraInner {
public:
    virtual void vf0();
    virtual void* vf1();
    virtual void vf2();
    virtual void* vf3();
};

class soraOuter {
public:
    u8 pad[0x58];
    soraInner* m_inner;
};

extern "C" void fn_27_42948(void* self);

extern "C" void fn_27_450A0(soraOuter* self) {
    fn_27_42948(self->m_inner->vf1());
}
