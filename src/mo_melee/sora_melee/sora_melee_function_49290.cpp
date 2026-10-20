#include <types.h>
#pragma force_active on

struct Self;

struct Inner {
    virtual void f0();
    virtual Self* f1(u32 v);
};

struct Self {
    u8 pad0[0x20];
    void* m_20;
    u8 pad1[0x24];
    Inner* m_48;
};

extern "C" void fn_27_46FE0(Self* self, void* obj, u32 idx, u32 val);

extern "C" void fn_27_49290(Self* self, u32 a, u32 b, u32 c) {
    Self* r = self->m_48->f1(c);
    fn_27_46FE0(r, self->m_20, a, b);
}
