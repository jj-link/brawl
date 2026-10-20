#include <types.h>
#pragma force_active on

struct fn27SubObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

struct fn27Owner {
    u8 pad[0x2c];
    fn27SubObj* m_sub;
};

extern "C" void fn_27_871C4(fn27Owner* self, u32 a, u32 b);

extern "C" void fn_27_B6E7C(fn27Owner* self, u32 a, u32 b) {
    self->m_sub->vf0();
    fn_27_871C4(self, a, b);
}
