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
    virtual void vfTarget(s32 v);
};

struct Outer {
    s32 unk0;
    s32 unk4;
    Inner* m_inner;
};

extern "C" {
void fn_27_D9F64(Outer* self, s16 v) {
    self->m_inner->vfTarget(v);
}
}
