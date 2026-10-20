#include <types.h>
#pragma force_active on

struct Fn27Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v13(int arg);
};

struct Fn27Obj {
    u8 _00[0x38];
    u32 m_38;
    u8 _3c[0xF0 - 0x3C];
    Fn27Sub* m_f0;
    u8 _f4[0x165 - 0xF4];
    u8 m_165;
};

extern "C" void fn_27_1C3AC(Fn27Obj* self) {
    self->m_f0->v13(-1);
    self->m_38 = 0;
    self->m_165 &= ~0x40;
}
