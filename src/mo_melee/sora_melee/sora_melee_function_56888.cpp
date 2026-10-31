#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4(u32 a, u32 b);
    u8 unk4[0x55];
    u8 m_flag;
};

extern "C" {
void fn_27_56888(soVirtBase* self, u32 a) {
    if (self->m_flag != 0) {
        return;
    }
    self->vfunc4(a, 0);
}
}
