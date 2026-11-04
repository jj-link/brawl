#include <gf/gf_model.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <types.h>
#pragma force_active on

struct Self {
    char pad0[0x12C];
    MuObject* object;
    MuObject* digits[6];
    char pad148[0x20];
    nw4r::g3d::ScnMdl* scnMdl;
    char pad16C[0x1F6];
    u8 flag362;
};

extern "C" {
extern nw4r::g3d::ScnMdl* lbl_805A033C;
extern char lbl_8059E670[8];
extern char lbl_8059E680[6];
extern const float lbl_805A2870;
extern const float lbl_805A2890;
extern const float lbl_805A28A8;
extern const float lbl_805A28AC;
extern const float lbl_805A28B0;

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B753C(MuObject*, float);
int sprintf(char*, const char*, ...);

void fn_8010C6C8(Self* self, u32 frame) {
    if (self->flag362 != 0) {
        char buf[6] = {};
        MuObject* sel[6];
        u32 sixty = 60;
        MuObject* obj = self->object;
        int i;
        MuObject** src;
        MuObject** dst;
        nw4r::g3d::ScnMdl* scn;
        if (frame < 60) {
            obj->setFrameVisible(lbl_805A2890);
        } else if (frame < 3600) {
            obj->setFrameVisible(lbl_805A28A8);
        } else {
            obj->setFrameVisible(lbl_805A28AC);
        }
        scn = self->scnMdl;
        lbl_805A033C->RemoveAnmObj((nw4r::g3d::ScnMdl::AnmObjType)(u32)scn);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(lbl_805A033C, scn, lbl_8059E680);
        src = self->digits;
        dst = sel;
        for (i = 0; i < 6; i++) {
            *dst = *src;
            sprintf(buf, lbl_8059E670, i);
            scn->RemoveAnmObj((nw4r::g3d::ScnMdl::AnmObjType)(u32)(*dst)->m_sceneModel);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scn, (*dst)->m_sceneModel, buf);
            src++;
            dst++;
        }
        u32 rem = frame % 216000;
        int minutes = rem / 3600;
        u32 s = rem % 3600;
        int seconds = s / 60;
        u32 fr = s % 60;
        int hund = (int)(lbl_805A28B0 * (float)fr / (float)sixty);

        sel[5]->setFrameTex((float)((minutes - minutes % 10) / 10));
        sel[4]->setFrameTex((float)(minutes % 10));
        sel[3]->setFrameTex((float)((seconds - seconds % 10) / 10));
        sel[2]->setFrameTex((float)(seconds % 10));
        sel[1]->setFrameTex((float)((hund - hund % 10) / 10));
        sel[0]->setFrameTex((float)(hund % 10));
        self->object->m_modelAnim->setUpdateRate(lbl_805A2870);
        fn_800B753C(self->object, lbl_805A28A8);
    }
}
}
