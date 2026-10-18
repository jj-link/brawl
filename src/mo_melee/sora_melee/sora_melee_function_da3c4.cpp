#include <types.h>
#pragma force_active on

struct Inner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(s16 value);
};

struct Outer {
    u32 unk0;
    u32 unk4;
    Inner* m_inner;
};

extern "C" void fn_27_DA3C4(Outer* self, s16 value) {
    self->m_inner->vf8(value);
}
