#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2(u32 a, u32 b, u32 c);
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(u32 a);
    u32 m_pad[0x19];
    u32 m_68;
};

struct fn27Param {
    u32 m_pad[3];
    u32 m_hi : 29;
    u32 m_flag : 1;
    u32 m_lo : 2;
};

extern "C" void fn_27_AE3C0(fn27Obj* self, u32 a, const fn27Param* b, const fn27Param* param) {
    if (param->m_flag == 0) {
        self->vfn2(0, 0, 0);
        self->m_68 = 0;
        self->vfn6(0);
    }
}
