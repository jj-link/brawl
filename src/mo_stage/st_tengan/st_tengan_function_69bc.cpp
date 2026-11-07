#include <ec/ec_mgr.h>
#include <snd/snd_system.h>
#pragma force_active on

struct GroundBase {
    unsigned char pad[0x3C];
};

struct Ground : GroundBase {
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
    virtual void fn_60_68F0();
    virtual void fn_60_6948();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_60_6588();
    virtual void startup();
    virtual void setNode();
    virtual void fn_60_1A80();
    virtual int fn_60_6580();
    virtual void fn_60_657C();
    virtual void fn_60_641C();
    virtual void fn_60_6574();
    virtual void fn_60_6568();
    virtual void fn_60_6558();
    virtual void fn_60_6548();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll(bool, unsigned long);
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_60_6544();
    virtual void fn_60_6540();
    virtual void fn_60_6538();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_60_6530();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_60_65B4();
    virtual void fn_60_65AC();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_60_65A4();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_60_69BC();
    virtual void fn_60_6CFC();
    virtual void fn_60_6D2C(int, int, int, void*);

    void setEnableCollisionStatus(bool);

    unsigned char pad40[4];
    nw4r::g3d::ScnMdl** p44;
    unsigned char pad48[0x114];
    unsigned char state;
    unsigned char pad15D[3];
    float f160;
    float* p164;
    unsigned char* p168;
    unsigned char b16C;
    unsigned char pad16D[0xB];
    float f178;
};

extern "C" {
extern const float lbl_60_rodata_F8;
extern const float lbl_60_rodata_FC;
}

extern "C" void fn_60_69BC(Ground* self, float delta) {
    if (self->fn_60_6580() == 0) {
        return;
    }
    self->f160 -= delta;
    if (self->f160 < lbl_60_rodata_F8) {
        self->f160 = lbl_60_rodata_F8;
    }
    self->f178 -= delta;
    if (self->f178 < lbl_60_rodata_F8) {
        self->f178 = lbl_60_rodata_F8;
    }

    switch (self->state) {
    case 0:
        self->fn_60_6D2C(0, 0, 1, 0);
        self->state = 1;
        break;
    case 1: {
        unsigned int r29 = 0;
        switch ((int)self->b16C) {
        case 0:
        case 1:
        case 2:
            if (self->p168[0] == 1) {
                r29 = 1;
                g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x460001), *self->p44, 1, false);
            }
            break;
        case 3:
            if (self->p168[0] == 1 || self->p168[1] == 1) {
                r29 = 1;
            }
            break;
        case 4:
            if (self->p168[1] == 1 || self->p168[2] == 1) {
                r29 = 1;
            }
            break;
        }
        if (r29 == 1) {
            self->fn_60_6D2C(1, 0, 1, &self->f178);
            self->setEnableCollisionStatus(false);
            self->state = 2;
        }
        break;
    }
    case 2:
        if (*self->p164 < lbl_60_rodata_FC) {
            switch ((int)self->b16C) {
            case 0:
            case 1:
            case 2:
                g_ecMgr->setParent(g_ecMgr->setEffect((EfID)0x460006), *self->p44, 1, false);
                self->fn_60_6D2C(0, 0, 1, 0);
                g_sndSystem->playSE((SndID)0x1C44, -1, 0, 0, -1);
                break;
            }
            self->setNodeVisibilityAll(true, 0);
            self->state = 3;
        }
        if (lbl_60_rodata_F8 == self->f178) {
            self->setVisibility(0);
        }
        break;
    case 3:
        if (lbl_60_rodata_F8 == *self->p164) {
            *self->p168 = 0;
            self->setVisibility(1);
            self->setEnableCollisionStatus(true);
            self->state = 0;
        }
        break;
    }
}
