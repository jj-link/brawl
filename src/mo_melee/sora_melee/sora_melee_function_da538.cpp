#include <types.h>
#pragma force_active on

class soInnerBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
};

class soOuterBase {
public:
    u32 m_unk0;
    u32 m_unk4;
    soInnerBase* m_inner;
};

extern "C" void fn_27_DA538(soOuterBase* self) {
    self->m_inner->vf4();
}
