#pragma force_active on
#include <types.h>

class Obj {
public:
    virtual void v0(s32 arg);
    u16 m_4;
    s16 m_6;
};

struct Other {
    u8 _pad[0x78];
    s32 m_78;
    s32 m_7c;
    u8 _pad80[4];
    s8 m_84;
};

struct Self {
    u8 _pad[0x8];
    Other* m_8;
    u8 _pad_c[0x10];
    Obj* m_1c;
    u8 _pad_20[0x1c];
    f32 m_3c;
    f32 getValue() const { return m_3c; }
};

extern "C" void fn_802EFF2C(Other*, void*);
extern "C" void fn_802F8584(Other*, Self*, s32);
extern "C" void fn_802E23CC(Self*, Obj*, void*);
extern "C" void fn_802E2378(void*, void*, f32);
extern "C" void fn_802F3D80(Other*, Self*);
extern "C" void fn_802E3E50(Self*);
extern "C" void fn_802F80F8(Other*, Self*);
extern "C" void fn_802EFE70();

extern f32 lbl_805A4354;
extern f32 lbl_805A4368;
extern f32 lbl_805A436C;

extern "C" s32 fn_802E3058(Self* self, Obj* arg) {
    char buf[0x20] __attribute__((aligned(16)));
    Other* child = self->m_8;
    if (child != 0 && child->m_7c != 0) {
        *(s8*)(buf + 0x10) = 5;
        *(Self**)(buf + 0x14) = self;
        *(Obj**)(buf + 0x18) = arg;
        fn_802EFF2C(self->m_8, buf + 0x10);
        return 0;
    }
    if (child != 0) {
        s32 val = child->m_7c;
        child->m_7c = val + 1;
        fn_802F8584(self->m_8, self, val);
    }

    Obj* m1c = self->m_1c;
    s8 hadOld = (s32)m1c != 0;
    if (m1c != 0 && m1c->m_4 != 0) {
        m1c->m_6 = m1c->m_6 - 1;
        if (m1c->m_6 == 0 && m1c != 0) {
            m1c->v0(1);
        }
    }

    self->m_1c = arg;
    if (arg->m_4 != 0) {
        arg->m_6 = arg->m_6 + 1;
    }

    fn_802E23CC(self, arg, buf);

    if (hadOld != 0 && lbl_805A4368 != self->m_3c) {
        self->m_3c = lbl_805A436C;
    }

    if (self->m_3c <= lbl_805A4354) {
        fn_802E2378(&self->m_1c, buf, self->getValue());
    }

    if (self->m_8 != 0) {
        fn_802F3D80(self->m_8, self);
    }

    fn_802E3E50(self);

    if (self->m_8 != 0) {
        fn_802F80F8(self->m_8, self);
        Other* endChild = self->m_8;
        if (--endChild->m_7c == 0 && endChild->m_78 != 0 && endChild->m_84 == 0) {
            fn_802EFE70();
        }
    }

    return 1;
}
