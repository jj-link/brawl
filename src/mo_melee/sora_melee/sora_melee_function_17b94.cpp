#include <types.h>
#pragma force_active on

extern const f32 lbl_27_rodata_340;

struct SubObj {
    u8 m_00[0x20];
    f32 m_20;
    u8 m_24_a : 2;
    u8 m_24_b : 1;
};

struct Inner {
    virtual void f0();
    virtual SubObj* f3(u32 a);
};

struct Outer {
    u8 m_00[0x90];
    Inner* m_90;
};

extern "C" {
f32 fn_27_17B94(Outer* self, u32 arg) {
    f32 r;
    if (self->m_90->f3(arg)->m_24_b == 0) {
        r = self->m_90->f3(arg)->m_20;
    } else {
        r = lbl_27_rodata_340;
    }
    return r;
}
}
