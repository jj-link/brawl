#include <types.h>
#pragma force_active on

class CObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual s32 vf3(s32 a, void* b);
    virtual void vf4();
    virtual void vf5(s32 a, s32 b);
    virtual void vf6();
};

struct DObj {
    u8 pad[0x64];
    CObj* m_a;   // 0x64
    u8 pad2[0x8];
    CObj* m_b;   // 0x70
};

struct BObj {
    u8 pad[0xd8];
    DObj* m_c;   // 0xd8
};

struct BaseItem {
    u8 pad[0x60];
    BObj* m_b;   // 0x60
};

extern "C" s32 sendTouchMessage__8BaseItemFiP5Vec3ff(BaseItem* p, s32 a, void* vec, f32 f);
extern "C" s32 fn_27_28ECF4(BaseItem* self);
extern const f32 lbl_27_rodata_46DC;

extern "C" s32 fn_27_29E58C(void* a, BaseItem* self, s32 arg, void* b, void* vec) {
    u8 val = (u8)sendTouchMessage__8BaseItemFiP5Vec3ff(self, arg, vec, lbl_27_rodata_46DC);
    switch (val) {
    case 1:
        return fn_27_28ECF4(self);
    case 2: {
        CObj* p0 = self->m_b->m_c->m_a;
        p0->vf5(arg, 0x10000000);
        CObj* p1 = self->m_b->m_c->m_b;
        return p1->vf3(7, self->m_b);
    }
    default:
        return 0;
    }
}
