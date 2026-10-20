#include <types.h>
#pragma force_active on

class fn_27_Inner {
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
    virtual void vf16();
};

class fn_27_Outer {
public:
    u32 m_pad[3];
    fn_27_Inner* m_inner;
};

extern "C" {
void fn_27_ABF78(fn_27_Outer* self) {
    self->m_inner->vf14();
}
}
