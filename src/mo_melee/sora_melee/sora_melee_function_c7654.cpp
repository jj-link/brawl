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
};

class fn_27_Outer {
public:
    u32 m_unk0;
    fn_27_Inner* m_inner;
    u32 m_unk8;
    u32 m_unkC;
};

extern "C" void fn_27_C7654(fn_27_Outer* self) {
    if (self->m_inner) {
        self->m_inner->vf8();
    }
    self->m_unk8 = 0;
    self->m_unkC = 0;
}
