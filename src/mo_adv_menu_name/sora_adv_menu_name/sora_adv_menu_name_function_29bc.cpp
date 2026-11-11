#include <gf/gf_3d_scene.h>
#include <gf/gf_application.h>

#pragma force_active on

extern "C" {
extern char lbl_28_data_0[];
extern const float lbl_28_rodata_94;
extern const float lbl_28_rodata_A0;

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void setFrameNode__8MuObjectFf(void*, float);
void setFrameVisible__8MuObjectFf(void*, float);
void changeNodeAnimNIf__8MuObjectFPCc(void*, const char*);
void changeVisAnimNIf__8MuObjectFPCc(void*, const char*);
void changeClrAnimNIf__8MuObjectFPCc(void*, const char*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
}

class AnimIface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void setRate(float) = 0;
};

struct AnimHolder {
    char pad0[0x8];
    AnimIface* a8;
    AnimIface* aC;
};

struct ObjRaw {
    char pad0[0xC];
    nw4r::g3d::ScnMdl* scnMdl;
    nw4r::g3d::ScnMdl* sceneModel;
    AnimHolder* anim;
};

struct State {
    char pad0[0x130];
    ObjRaw* obj130;
    char pad1[4];
    ObjRaw* obj138;
    char pad2[4];
    ObjRaw* obj140;
    ObjRaw* obj144;
    ObjRaw* obj148;
    ObjRaw* obj14c;
    ObjRaw* obj150;
    nw4r::g3d::ScnMdl* mdl154;
    nw4r::g3d::ScnMdl* mdl158;
    nw4r::g3d::ScnMdl* mdl15c;
    char pad3[0x168 - 0x160];
    int mode;
    char pad4[0x21c - 0x16c];
    int state;
    char pad5[0x350 - 0x220];
    unsigned char flag350;
};

extern "C" void fn_28_29BC(State* self) {
    char* data = lbl_28_data_0;
    ObjRaw* a = self->obj130;
    ObjRaw* b = self->obj138;
    ObjRaw* c = self->obj140;

    self->state = 0;
    setFrameNode__8MuObjectFf(a, lbl_28_rodata_A0);
    setFrameVisible__8MuObjectFf(a, lbl_28_rodata_94);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdl15c, self->obj140->sceneModel, data + 0xec);
    changeNodeAnimNIf__8MuObjectFPCc(b, data + 0x12c);
    changeVisAnimNIf__8MuObjectFPCc(b, data + 0x12c);
    b->anim->aC->setRate(lbl_28_rodata_94);
    b->anim->a8->setRate(lbl_28_rodata_94);
    changeClrAnimNIf__8MuObjectFPCc(c, data + 0x144);

    if (self->mode == 1) {
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj144->sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj148->sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj14c->sceneModel);
        g_gfSceneRoot->add(gfSceneRoot::Layer_Info, self->obj150->sceneModel);
    }

    nw4r::g3d::ScnMdl* mdl = self->mdl154;
    nw4r::g3d::ScnMdl* other = self->mdl15c;
    g_gfSceneRoot->add(gfSceneRoot::Layer_Info, mdl);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(mdl, other, data + 0xec);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdl154, self->mdl158, data + 0xf4);

    self->flag350 = 1;
    g_gfApplication->unkD0.endKeepScreen();
    fn_801AAFF0(a->scnMdl, 0x96);
    fn_801AB014(a->scnMdl, 0x96);
    fn_801AAFF0(b->scnMdl, 0x97);
    fn_801AB014(b->scnMdl, 0x97);
    fn_801AAFF0(c->scnMdl, 0x98);
    fn_801AB014(c->scnMdl, 0x98);
}