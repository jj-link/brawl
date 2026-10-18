#include <types.h>
#pragma force_active on

struct fnInner {
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

struct fnOuter {
    u32 unk0;
    u32 unk4;
    fnInner* m_inner;
};

extern "C" {
void fn_27_D9EC4(fnOuter* self, s32 value) {
    self->m_inner->vf8((s16)value);
}
}
