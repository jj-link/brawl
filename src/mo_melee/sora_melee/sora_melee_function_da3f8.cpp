#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual ~fn27Inner();
};

class fn27Outer {
public:
    u32 unk0;
    u32 unk4;
    fn27Inner* m_inner;
};

extern "C" {
void fn_27_DA3F8(fn27Outer* self) {
    self->m_inner->vf4();
}
}
