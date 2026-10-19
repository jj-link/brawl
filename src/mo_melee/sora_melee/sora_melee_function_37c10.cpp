#include <types.h>
#pragma force_active on

extern "C" void fn_27_380E8();

class soInnerWork {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class soOuterWork {
public:
    u32 m_pad[2];
    soInnerWork* m_inner;
};

extern "C" void fn_27_37C10(soOuterWork* self) {
    self->m_inner->vf1();
    fn_27_380E8();
}
