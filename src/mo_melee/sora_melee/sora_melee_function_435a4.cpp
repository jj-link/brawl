#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual u32 f3(u32 v);
};

class Owner {
public:
    u8 pad0[0x30];
    u32 m_30;
    s32 m_34;
    u8 m_38[0x20];
    Inner* m_58;
};

extern "C" s32 fn_27_41CF8(u32 r3, void* p, u32 a, u32 b, u32 c, s32 d);

extern "C" void fn_27_435A4(Owner* self, u32 a, u32 b) {
    u32 r = self->m_58->f3(b);
    s32 d = fn_27_41CF8(r, self->m_38, self->m_30, a, b, self->m_34);
    self->m_34 += d;
}
