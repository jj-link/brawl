#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
int sprintf(char*, const char*, ...);
int fn_800B61C0(MuObject* obj);
void fn_800B5854(MuObject* obj, int a, int b, int c, int d);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern char lbl_8059E518[8];
extern nw4r::g3d::ScnMdl* lbl_805A030C;
extern float lbl_805A2728;
extern float lbl_805A2740;

class VCall {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(float f);
    virtual void vf9();
    virtual void vf10(void* a, void* b);
    virtual void vf11(void* a, void* b);
    virtual void vf12();
    virtual void vf13(void* a);
    char pad4[0xE0];
    void* unkE4;
};

struct SelfObj {
    s32 unk0;
    u8 unk4;
    s32 unk8;
    MuObject* unkC;
    s32 unk10;
    VCall* unk14;
};

extern "C" int fn_800FDDD4(SelfObj* self) {
    switch (self->unk10) {
    case 2: {
        char sp10[8];
        if (fn_800B61C0(self->unkC)) {
            MuObject* obj = self->unkC;
            void* r30 = obj->m_sceneModel;
            if (self->unk0 == 0) {
                ((VCall*)lbl_805A030C)->vf13(r30);
            } else {
                self->unk14->vf13(r30);
            }
            r30 = obj->m_sceneModel;
            if (self->unk0 == 0) {
                sprintf(sp10, lbl_8059E518, self->unk4 + 1);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A030C, r30, sp10);
            } else {
                self->unk14->vf11(self->unk14->unkE4, r30);
            }
            fn_800B5854(obj, 3, 3, 1, 0);
            obj->setFrameTex(lbl_805A2740 + (float)(s32)self->unk4);
            ((VCall*)obj->m_modelAnim->m_anmObjTexPatRes)->vf8(lbl_805A2728);
            self->unk10 = 3;
        }
        break;
    }
    case 3: {
        char sp8[8];
        if (fn_800B61C0(self->unkC)) {
            MuObject* obj = self->unkC;
            void* r30 = obj->m_sceneModel;
            if (self->unk0 == 0) {
                ((VCall*)lbl_805A030C)->vf13(r30);
            } else {
                self->unk14->vf13(r30);
            }
            r30 = obj->m_sceneModel;
            if (self->unk0 == 0) {
                sprintf(sp8, lbl_8059E518, self->unk4 + 1);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A030C, r30, sp8);
            } else {
                self->unk14->vf11(self->unk14->unkE4, r30);
            }
            fn_800B5854(obj, 4, 3, 1, 0);
            obj->setFrameTex(lbl_805A2740 + (float)(s32)self->unk4);
            ((VCall*)obj->m_modelAnim->m_anmObjTexPatRes)->vf8(lbl_805A2728);
            self->unk10 = 4;
        }
        break;
    }
    }
    return self->unk8;
}
