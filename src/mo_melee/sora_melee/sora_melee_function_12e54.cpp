#include <types.h>
#pragma force_active on

extern "C" void fn_80098388(u32 a, u32 b, float c);

struct SubObj {
    virtual void vf0();
    virtual u32* vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Owner {
    u8 pad[0x30];
    u32 m_30;
    SubObj* m_34;
};

extern "C" {
void fn_27_12E54(Owner* self, float f) {
    if (self->m_30 != 0) {
        u32* p = self->m_34->vf1();
        fn_80098388(self->m_30, *p, f);
    }
}
}
