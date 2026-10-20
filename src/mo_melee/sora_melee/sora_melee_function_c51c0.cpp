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
    virtual ~soInnerBase();
};

class soOuter {
public:
    u32 m_pad0;
    u32 m_pad4;
    soInnerBase* m_inner;
};

extern "C" void fn_27_C51C0(soOuter* self) {
    self->m_inner->vf4();
}
