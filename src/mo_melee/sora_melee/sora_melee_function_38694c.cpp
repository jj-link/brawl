#include <types.h>
#pragma force_active on
#pragma fp_contract off

class VObj {
public:
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
    virtual void v11();
    virtual f32 v12(u32);
    virtual void v13(u32, f32);
};

class VObj2 {
public:
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(void*, f32);
};

struct Sub {
    char pad0[8];
    VObj2* m_8;
    char pad1[0x58];
    VObj* m_64;
};

struct Self {
    char pad[0xD8];
    Sub* m_d8;
};

struct RData {
    f32 f0;
    f32 f4;
    f32 f8;
};

extern "C" const RData lbl_27_rodata_7C48;

struct Local {
    s32 a;
    f32 b;
    f32 c;
    s8 d;
    s8 e;
    s8 f;
    s8 g;
};

extern "C" void fn_27_38694C(void* unused, Self* self) {
    const RData* rd = &lbl_27_rodata_7C48;

    f32 result = self->m_d8->m_64->v12(0x11000016);

    f32 dir;
    if (result < rd->f8) {
        dir = rd->f0;
    } else {
        dir = rd->f4;
    }

    self->m_d8->m_64->v13(0x11000019, dir);

    s32 id;
    if (rd->f0 == dir) {
        id = 0x1d7;
    } else {
        id = 0x1d6;
    }

    Local local;
    local.a = id;
    local.b = rd->f8;
    local.c = rd->f4;
    local.d = 0;
    local.e = 0;
    local.f = 0;
    local.g = 0;

    self->m_d8->m_8->v30(&local, rd->f8);
    self->m_d8->m_64->v13(0x11000018, rd->f8);
}