#include <gf/gf_3d_scene.h>
#pragma force_active on

struct Flags6C {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char rest : 6;
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData();
    virtual void slot25();
    virtual void setupMelee();
    virtual void slot27(unsigned long);
    char pad40[4];
    nw4r::g3d::ScnMdl** models;
    char pad48[0x24];
    Flags6C flags;
};

extern "C" void fn_27_25F8B8(Ground*, nw4r::g3d::ScnMdl*, int);

extern "C" void fn_27_260604(Ground* self, int enabled, int index)
{
    if (enabled != 0 && !self->flags.b1) {
        fn_27_25F8B8(self, self->models[index], 0);
        self->slot27(self->flags.b0);
    } else if (enabled == 0 && self->flags.b1) {
        g_gfSceneRoot->remove(self->models[index]);
    }
}
