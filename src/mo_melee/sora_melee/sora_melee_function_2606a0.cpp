#include <gf/gf_3d_scene.h>
#pragma force_active on

extern "C" void fn_27_25F8B8(void*, void*, int);

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void fn_27_260174();
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
    virtual void fn_27_260920();
    virtual void init();
    virtual void fn_27_25F4B0();
    virtual void fn_27_260228();
    virtual void loadGroundData();
    virtual void fn_27_25F524();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect(unsigned long);
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual unsigned int getModelCount();
    char pad40[4];
    nw4r::g3d::ScnMdl** models;
};

void Ground::setVisibilityAttachedEffect(unsigned long visibility) {
    for (unsigned int i = 0; i < getModelCount(); i++) {
        if (visibility == 1) {
            fn_27_25F8B8(this, models[i], 0);
        } else {
            g_gfSceneRoot->remove(models[i]);
        }
    }
    setVisibility(visibility);
}
