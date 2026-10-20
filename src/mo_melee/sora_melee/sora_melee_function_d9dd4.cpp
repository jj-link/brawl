#include <types.h>
#pragma force_active on

class soSub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class soOuter {
public:
    u8 m_pad[0x10];
    soSub m_sub;
};

extern "C" void fn_27_D9DD4(soOuter* self) {
    soSub* p = &self->m_sub;
    p->vf3();
}
