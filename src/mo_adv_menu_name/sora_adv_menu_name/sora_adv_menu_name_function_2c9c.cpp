#include <mu/mu_object.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_application.h>

#pragma force_active on

extern "C" {
extern char lbl_28_data_0[];
extern const float lbl_28_rodata_94;
extern const float lbl_28_rodata_A0;

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
}

struct State {
    char pad0[0x124];
    unsigned char flag;
    char pad1[0xb];
    MuObject* obj130;
    MuObject* obj134;
    MuObject* obj138;
    MuObject* obj13c;
    MuObject* obj140;
    MuObject* obj144;
    MuObject* obj148;
    MuObject* obj14c;
    MuObject* obj150;
    nw4r::g3d::ScnMdl* mdl154;
    nw4r::g3d::ScnMdl* mdl158;
    nw4r::g3d::ScnMdl* mdl15c;
    char pad2[8];
    int mode;
    char pad3[0x168];
    int state;
    char pad4[0x78];
    unsigned char flag350;
};

extern "C" void fn_28_2C9C(State* self) {
    char* data = lbl_28_data_0;
    MuObject* a = self->obj130;
    MuObject* b = self->obj134;
    MuObject* c = self->obj13c;

    self->flag = 1;
    self->state = 0;
    a->setFrameNode(lbl_28_rodata_A0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        self->mdl158, self->obj13c->m_sceneModel, data + 0xec);
    b->changeNodeAnimNIf(data + 0x12c);
    b->changeVisAnimNIf(data + 0x12c);
    b->m_modelAnim->setUpdateRate(lbl_28_rodata_94);
    c->changeClrAnimNIf(data + 0x15c);

    if (self->mode == 1) {
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj144->m_sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj148->m_sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj14c->m_sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj150->m_sceneModel);
    }

    nw4r::g3d::ScnMdl* mdl = self->mdl154;
    nw4r::g3d::ScnMdl* other = self->mdl15c;
    g_gfSceneRoot->add(gfSceneRoot::Layer_Info, mdl);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, other, data + 0xec);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        self->mdl154, self->mdl158, data + 0xf4);

    self->flag350 = 1;
    g_gfApplication->unkD0.endKeepScreen();
    fn_801AAFF0(a->m_scnMdl, 0x96);
    fn_801AB014(a->m_scnMdl, 0x96);
    fn_801AAFF0(b->m_scnMdl, 0x97);
    fn_801AB014(b->m_scnMdl, 0x97);
    fn_801AAFF0(c->m_scnMdl, 0x98);
    fn_801AB014(c->m_scnMdl, 0x98);
}
