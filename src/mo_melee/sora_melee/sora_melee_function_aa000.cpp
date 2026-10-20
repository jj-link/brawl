#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
};

class fn27Outer {
public:
    u8 pad[0x30];
    fn27Inner* m_inner;
};

extern "C" void fn_27_AA000(fn27Outer* self) {
    self->m_inner->vf8();
}
