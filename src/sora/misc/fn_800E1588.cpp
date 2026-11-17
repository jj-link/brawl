#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(f32 frame);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void* arg);
};

extern "C" {
extern Object_vptr_0* lbl_805A02DC;
extern const f32 lbl_805A23B0;
extern const f32 lbl_805A23C0;
extern const f32 lbl_805A23F0;
extern const u8 lbl_805A23E8[8];
void fn_800E5318(void*);
void fn_800E1840(void*, u32, s32);
void fn_801B4CB0(void*, void*, int);
void fn_800B6838(MuObject*, const f32*);
}

struct Self {
    u8 flag80 : 1;
    u8 flag40 : 1;
    u8 flag20 : 1;
    u8 rest : 5;
    char pad1[3];
    int unk4;
    char pad8[0xC];
    int state14;
    char pad18[4];
    u32 unk1C;
    char pad20[8];
    MuObject* objs[203];
    s32 state354;
};

inline void updateModel(Self* self, void* model) {
    if (self->flag20) {
        fn_801B4CB0(lbl_805A02DC, model, self->unk4);
    }
}

extern "C" void fn_800E1588(Self* self, u32 arg1, s32 arg2, s32 arg3) {
    s32 count;
    MuObject* o;
    const u8* tbl;
    MuObject** q;
    u32 frame;
    s32 k;
    s32 m;
    u32 cnt;

    self->unk1C = arg1;
    if (self->state354 == 2) {
        fn_800E5318(self);
    }
    if ((self->state14 != 2 && self->state14 != 4) || arg3 != 0) {
        {
            s32 i;
            MuObject** p = self->objs - 8;
            for (i = 2; i < 6; i++) {
                lbl_805A02DC->slot13(p[10]->m_sceneModel);
                p++;
            }
        }
        {
            MuObject** p = self->objs - 4;
            s32 i;
            for (i = 6; i < 0x18; i++) {
                lbl_805A02DC->slot13(p[10]->m_sceneModel);
                p++;
            }
        }
        count = 1;
        if (arg3 != 0) {
            count = 6;
        }
        cnt = arg1;
        if (cnt > 0x3E7) {
            cnt = 0x3E7;
        }
        k = 0;
        tbl = lbl_805A23E8;
        for (; k < 3 && (cnt != 0 || k <= 0); tbl += 2, k++, cnt /= 10) {
            u8 idx = (arg3 != 0) ? tbl[1] : tbl[0];
            q = (MuObject**)((char*)self + ((idx * 4) & 0x3FC));
            frame = cnt % 10;
            for (m = 0; m < count; m++, q++) {
                o = q[10];
                updateModel(self, o->m_sceneModel);
                o->setFrameTex((f32)frame);
                ((Object_vptr_0*)o->m_modelAnim->m_anmObjTexPatRes)->slot8(lbl_805A23B0);
                if (arg3 == 0) {
                    ((Object_vptr_0*)o->m_modelAnim->m_anmObjVisRes)->slot8(lbl_805A23B0);
                    o->setFrameVisible(lbl_805A23C0);
                }
            }
        }
        f32 f31;
        if (self->flag80) {
            f31 = lbl_805A23F0;
        } else {
            f31 = lbl_805A23C0;
        }
        MuObject* o2 = self->objs[2];
        updateModel(self, o2->m_sceneModel);
        ((Object_vptr_0*)o2->m_modelAnim->m_anmObjVisRes)->slot8(lbl_805A23B0);
        o2->setFrameVisible(f31);
        f32 pos[3];
        pos[0] = *(f32*)((char*)o2 + 0x3C);
        pos[1] = *(f32*)((char*)o2 + 0x40);
        pos[2] = *(f32*)((char*)o2 + 0x44);
        pos[0] = lbl_805A23B0;
        pos[1] = lbl_805A23B0;
        fn_800B6838(o2, pos);
        if (arg2 != 0) {
            fn_800E1840(self, arg1, arg3);
        }
    }
}
