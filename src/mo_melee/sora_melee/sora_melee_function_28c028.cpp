#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_4610;
extern const float lbl_27_rodata_461C;

class SoraIfaceA {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(u32 a, u32 b);
};

class SoraIfaceB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v6(float f, s32 n, void* p);
    virtual void v7();
    virtual void v8(float f, s32 n, void* p, s32 flag);
};

struct SoraMeleeFn27 {
    u8 m_pad0[0xcc];
    u8 m_pad1[0x2aac - 0xcc];
    SoraIfaceA m_a;
    u8 m_pad2[0x33d0 - 0x2aac - 4];
    SoraIfaceB m_b;
};

extern "C" void fn_27_28C028(SoraMeleeFn27* self, u32 x) {
    self->m_a.v7(x, 0x10000004);
    self->m_b.v8(lbl_27_rodata_4610, 5, (void*)&self->m_pad0[0xcc], 1);
    self->m_b.v6(lbl_27_rodata_461C, 5, (void*)&self->m_pad0[0xcc]);
}
