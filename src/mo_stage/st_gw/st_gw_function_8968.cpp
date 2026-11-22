#pragma force_active on
#include <mt/mt_prng.h>
extern "C" const float lbl_63_rodata_A8[];

struct GroundBase {
    char pad[0x3c];
};

class Ground : public GroundBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
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
    virtual void fn_63_65C8();
    virtual void fn_63_66AC();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(bool, unsigned long, unsigned long, bool, bool);
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_63_3334();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
    virtual void fn_63_8CE4();
    virtual void fn_63_8C60();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit(unsigned long, unsigned long);
    virtual void disableHit(unsigned long, unsigned long);

    char m_pad40[0x1d4 - 0x40];
    struct Nodes { char a[1]; } nodes[48];
    char m_pad204[0x23c - 0x204];
    unsigned char m_state;
    char m_pad23d[0x27c - 0x23d];
    unsigned char m_27c;
};

extern "C" void fn_63_8968(Ground* self) {
    const float* values = lbl_63_rodata_A8;
    unsigned char state = self->m_state;
    int off = (state * 4 - state) * 4;
    self->setNodeVisibility(false, 0, *(unsigned long*)&self->nodes[off].a[0], true, false);
    self->setNodeVisibility(false, 0, *(unsigned long*)&self->nodes[off].a[4], true, false);
    self->setNodeVisibility(false, 0, *(unsigned long*)&self->nodes[off].a[8], true, false);
    self->disableHit(self->m_state, 0);

    float r = randf();
    switch (self->m_state) {
    case 0:
        if (r < values[20]) {
            self->m_state = 0;
        } else {
            self->m_state = 1;
        }
        break;
    case 1:
        if (r < values[21]) {
            self->m_state = 0;
        } else if (r < values[22]) {
            self->m_state = 1;
        } else {
            self->m_state = 2;
        }
        break;
    case 2:
        if (r < values[21]) {
            self->m_state = 1;
        } else if (r < values[22]) {
            self->m_state = 2;
        } else {
            self->m_state = 3;
        }
        break;
    case 3:
        if (r < values[20]) {
            self->m_state = 2;
        } else {
            self->m_state = 3;
        }
        break;
    }

    unsigned char s2 = self->m_state;
    int off2 = (s2 * 4 - s2) * 4;
    self->setNodeVisibility(true, 0, *(unsigned long*)&self->nodes[off2].a[0], true, false);
    self->setNodeVisibility(true, 0, *(unsigned long*)&self->nodes[off2].a[4], true, false);
    if (self->m_27c == 1) {
        self->enableHit(self->m_state, 0);
    }
}
