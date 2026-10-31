#include <types.h>
#pragma force_active on

class soVirtualBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5(u32 a, u32 b, u32 c, u32 d) = 0;

    u8 m_04[0x44];
    u32 m_48;
};

extern "C" {
void fn_27_576C8(soVirtualBase* self) {
    if (self->m_48 == 0xFFFFFFFF) {
        return;
    }
    self->vf5(self->m_48, 0, 0, 0);
}
}
