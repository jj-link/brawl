#include <types.h>
#pragma force_active on

extern f32 lbl_27_rodata_A0C;

class Pad8 {
public:
    u32 m_a;
    u32 m_b;
};

class Sub : public Pad8 {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4(s32, s32) = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual s32 v11() = 0;
    virtual void v12() = 0;
    virtual void v13(s32, f32) = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual s32 v18() = 0;
    virtual void v19() = 0;
    virtual void v20(s32, s32) = 0;
    virtual void v21(s32) = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual s32 v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
};

class Owner {
public:
    u8 m_pad000[0x3c];
    Sub* m_sub;
};

struct Flags {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" void fn_27_754AC(Owner* self, Flags* f) {
    if (f->a == 0 && f->b == 0 && f->c == 0) {
        self->m_sub->v25();
        return;
    }
    s32 n = self->m_sub->v11();
    if (n > 0x1F) {
        n = 0x1F;
    }
    for (s32 i = 0; i < n; i++) {
        if (!(f->b & (1 << i))) {
            self->m_sub->v4(0, i);
        }
    }
    n = self->m_sub->v18();
    if (n > 0x1F) {
        n = 0x1F;
    }
    for (s32 i = 0; i < n; i++) {
        if (!(f->c & (1 << i))) {
            self->m_sub->v13(i, lbl_27_rodata_A0C);
        }
    }
    s32 count = self->m_sub->v24();
    if (count > 0) {
        self->m_sub->v20(~f->a, 0);
        for (s32 i = 1; i < count; i++) {
            self->m_sub->v21(i);
        }
    }
}
