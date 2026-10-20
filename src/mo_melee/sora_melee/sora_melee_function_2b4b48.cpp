#include <types.h>
#pragma force_active on

class soCallee {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

class soCaller {
public:
    u8 m_pad0[0x8c];
    soCallee m_a;
    u8 m_pad1[0xd8 - 0x90];
    soCallee m_b;
    u8 m_pad2[1];
    u8 m_flags;
};

extern "C" {
void fn_27_2B4B48(soCaller* self, bool flag) {
    self->m_a.vf6();
    if (flag && ((self->m_flags >> 7) & 1)) {
        self->m_b.vf6();
    }
}
}
