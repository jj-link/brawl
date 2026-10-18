#include <types.h>
#pragma force_active on

class soInnerObj {
public:
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

struct soOuterObj {
    u32 unk0;
    u32 unk4;
    soInnerObj* m_8;
};

extern "C" void fn_27_DA0A4(soOuterObj* self, s32 value) {
    self->m_8->vf8(value);
}
