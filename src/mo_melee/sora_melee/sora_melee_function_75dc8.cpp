#include <types.h>
#pragma force_active on

struct fn_27_75DC8_Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

struct fn_27_75DC8_Outer {
    u8 pad[0x2c];
    fn_27_75DC8_Inner* m_inner;
};

extern "C" void fn_27_75DC8(fn_27_75DC8_Outer* self) {
    return self->m_inner->vf6();
}
