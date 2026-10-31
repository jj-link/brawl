#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn5(u32 a, s32 b);
    u8 pad[0x30 - 4];
    u32 m_30;
};

extern "C" void fn_27_B5F54(fn27Obj* self, u32 a, u32 b, u32 c) {
    u32 v = self->m_30;
    if (v == 0xffffffff) {
        return;
    }
    if (v != c) {
        return;
    }
    self->vfn5(a, 1);
}
