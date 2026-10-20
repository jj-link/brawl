#include <types.h>
#pragma force_active on

class SubBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

class Outer {
public:
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    SubBase m_sub;
};

extern "C" void fn_27_1E6BA0(Outer* self) {
    self->m_sub.vf3();
}
