#include <types.h>
#pragma force_active on

struct fn_27_Iface {
    virtual void vf0() = 0;
    virtual void* vf3(u32 arg) = 0;
};

struct fn_27_Owner {
    u8 pad0[0x28];
    fn_27_Iface* m_iface;
    u8 pad1[0x54 - 0x2C];
    void* m_x54;
};

extern "C" void fn_27_2F06C(void* r3, void* r4, u32 a, u32 b, u32 c, u32 d);

extern "C" void fn_27_2AC80(fn_27_Owner* self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    void* r = self->m_iface->vf3(a5);
    fn_27_2F06C(r, self->m_x54, a3, a2, a4, a1);
}
