#include <types.h>
#pragma force_active on

class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

class soOuter {
public:
    u32 m_pad[4];
    soBase m_base;
};

extern "C" {
void fn_27_F0314(soOuter* p) {
    soBase& ref = p->m_base;
    ref.vf13();
}
}
