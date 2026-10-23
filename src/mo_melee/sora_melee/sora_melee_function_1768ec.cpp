#include <types.h>
#pragma force_active on

struct Local {
    s32 a;
    f32 b;
    f32 c;
    s8 d, e, f, g;
};

struct Local2 {
    s32 h;
    s32 i;
    u8 pad[0x20];
};

class Sub {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30(Local* p) = 0;
};

struct Ctx {
    u8 pad[8];
    Sub* m_sub;
};

extern "C" {
extern const f32 lbl_27_rodata_22E8;
extern const f32 lbl_27_rodata_22EC;

void fn_27_1744D4(void* a, void* b);
void fn_27_174C08(void* a, void* b, void* c);

void fn_27_1768EC(void* arg0, void* arg1) {
    Local local;
    Local2 local2;

    local.a = 0x17E;
    local.b = lbl_27_rodata_22E8;
    local.c = lbl_27_rodata_22EC;
    local.d = 0;
    local.e = 0;
    local.f = 0;
    local.g = 0;

    Ctx* ctx = *(Ctx**)((u8*)arg1 + 0xD8);
    Sub* sub = ctx->m_sub;
    sub->v30(&local);

    fn_27_1744D4(arg0, arg1);

    local2.h = 0xC;
    local2.i = 0;
    fn_27_174C08(arg0, &local2, arg1);
}
}
