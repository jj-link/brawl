#include <types.h>
#pragma force_active on

class fnSubBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fnOuter {
public:
    u32 m_0;
    u32 m_4;
    u32 m_8;
    fnSubBase m_sub;
};

extern "C" void fn_27_D66E8(fnOuter* self) {
    self->m_sub.vf4();
}
