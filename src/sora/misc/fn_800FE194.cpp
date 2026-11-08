#include <types.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on

extern "C" {
int sprintf(char*, const char*, ...);
int fn_800B61C0(MuObject*);
void fn_800B5854(MuObject*, int, int, int, int);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern char lbl_8059E518[8];
extern nw4r::g3d::ScnMdl* lbl_805A030C;
extern float lbl_805A2728;
extern float lbl_805A2740;

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
    virtual void slot8(float);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, void*);
    virtual void slot12();
    virtual void slot13(void*);
    char pad4[0xE0];
    void* unkE4;
};

struct SelfObj {
    s32 unk0;
    u8 unk4;
    s32 unk8;
    MuObject* unkC;
    s32 unk10;
    Object_vptr_0* unk14;
};

extern "C" s32 fn_800FE194(SelfObj* self) {
    char sp8[8];
    if (self->unk10 == 5 && fn_800B61C0(self->unkC)) {
        MuObject* obj = self->unkC;
        void* model = obj->m_sceneModel;
        if (self->unk0 == 0) {
            ((Object_vptr_0*)lbl_805A030C)->slot13(model);
        } else {
            self->unk14->slot13(model);
        }
        model = obj->m_sceneModel;
        if (self->unk0 == 0) {
            sprintf(sp8, lbl_8059E518, self->unk4 + 1);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A030C, model, sp8);
        } else {
            self->unk14->slot11(self->unk14->unkE4, model);
        }
        fn_800B5854(obj, 6, 3, 1, 0);
        u32 n = (u32)self->unk4 ^ 0x80000000u;
        obj->setFrameTex(lbl_805A2740 + (float)(s32)(n ^ 0x80000000u));
        ((Object_vptr_0*)obj->m_modelAnim->m_anmObjTexPatRes)->slot8(lbl_805A2728);
        self->unk10 = 6;
    }
    return self->unk8;
}
