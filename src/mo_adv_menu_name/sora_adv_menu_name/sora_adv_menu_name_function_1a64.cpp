#include <mu/mu_object.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_application.h>

#pragma force_active on

extern "C" {
extern char lbl_28_data_0[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

struct State {
    char pad0[0x4c];
    int state;
    char pad1[0xf4];
    MuObject* obj144;
    MuObject* obj148;
    MuObject* obj14c;
    MuObject* obj150;
    nw4r::g3d::ScnMdl* mdl154;
    nw4r::g3d::ScnMdl* mdl158;
    nw4r::g3d::ScnMdl* mdl15c;
    char pad2[8];
    int mode;
    char pad3[0x1e4];
    unsigned char flag350;
};

extern "C" void fn_28_1A64(State* self) {
    char* data = lbl_28_data_0;
    self->obj150->changeNodeAnimNIf(data + 0xfc);
    self->state = 1;
    if (self->flag350 == 0) {
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
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdl154, self->mdl158, data + 0xf4);
        self->flag350 = 1;
        g_gfApplication->unkD0.endKeepScreen();
    }
}
