#include <ec/ec_mgr.h>
#pragma force_active on

extern const char lbl_48_data_870[];
extern const float lbl_48_rodata_38;

struct GroundBase {
    char pad[0x3c];
};

class GroundObj : public GroundBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_48_2AF0();
    virtual void processUpdate();
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
    virtual void renderDebug();
    virtual void init();
    virtual void fn_48_2A98();
    virtual void fn_48_2E30();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_48_203C();
    virtual void startup();
    virtual void fn_48_2F68();
    virtual void fn_48_7BC();
    virtual float* fn_48_2034();
    virtual void fn_48_2030();
    virtual void fn_48_1F20();
    virtual void fn_48_2028();
    virtual void fn_48_201C();
    virtual void fn_48_200C();
    virtual void fn_48_1FFC();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_48_1FF8();
    virtual void fn_48_1FF4();
    virtual void fn_48_1FEC();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);

    char pad40[4];
    nw4r::g3d::ScnMdl** model;      // 0x44
    char pad48[0x64 - 0x48];
    float f64;                      // 0x64
    char pad68[0x150 - 0x68];
    unsigned char state;            // 0x150
    char pad151[0x158 - 0x151];
    float* ptr158;                  // 0x158
    char pad15c[0x160 - 0x15c];
    unsigned char mode;             // 0x160
};

extern "C" void fn_48_2E30(GroundObj* self) {
    switch (self->state) {
    case 0: {
        float* anim = self->fn_48_2034();
        if (anim == 0) {
            return;
        }
        switch (self->mode) {
        case 0: {
            u32 effect;
            float k;
            self->f64 = anim[1];
            g_ecMgr->setDrawPrio(1);
            effect = g_ecMgr->setEffect((EfID)0x360001);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(effect, *self->model, lbl_48_data_870, false);
            k = lbl_48_rodata_38;
            Vec3f scl(k, k, k);
            g_ecMgr->setScl(effect, &scl);
            break;
        }
        case 1:
            self->f64 = anim[2];
            break;
        }
        self->state = 1;
    }
    case 1:
        *self->ptr158 = self->getMotionFrame(0);
        break;
    }
}
