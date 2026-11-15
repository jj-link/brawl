#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(f32); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(s32);
};
class Obj0F0 : public Object_vptr_0 {
public:
    char pad[0xE0];
    s32 unkE4;
};
struct Self {
    char pad0[0x88];
    MuObject* p88;
    char pad1[0x14];
    MuObject* pA0[5];
    char pad2[0x3C];
    Obj0F0* pF0;
    char pad3[0x4B4];
    s32 v5A8[5];
};
extern "C" {
extern const f32 lbl_805A23B0;
void fn_801B4CB0(void*, void*, s32);
void fn_800B22B8(void*);
}
extern "C" void fn_800E22A0(Self* self, u32 count) {
    MuObject* o2;
    MuObject* node;
    Self* cursor;
    Obj0F0* ctl = self->pF0;
    s32 j;
    s32 n;

    while ((n = ctl->unkE4) != 0) {
        if (n != 0) ctl->slot12(n - 1);
    }
    if (count > 99999) count = 99999;
    cursor = self;
    j = 0;
    for (; j < 5 && (count != 0 || j <= 0); j++) {
        o2 = cursor->pA0[0];
        f32 digit = (f32)(count % 10);
        o2->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(lbl_805A23B0);
        o2->setFrameTex(digit);
        fn_801B4CB0(ctl, o2->m_sceneModel, cursor->v5A8[0]);
        count /= 10;
        cursor = (Self*)((char*)cursor + 4);
    }
    node = self->p88;
    f32 jf = (f32)j;
    node->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_805A23B0);
    node->setFrameNode(jf);
    fn_800B22B8(node);
    for (s32 k = 0; k < j; k++) {
        fn_800B22B8(self->pA0[k]);
    }
}
