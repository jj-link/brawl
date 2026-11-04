#include <gr/ground.h>
#pragma force_active on
struct GroundViewBase { char pad[0x3c]; };
struct GroundView : GroundViewBase {
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
    virtual void fn_51_12158();
    virtual void fn_51_12248();
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
    virtual void fn_51_33B4();
    virtual void startup();
    virtual void setNode();
    virtual void fn_51_994();
    virtual void fn_51_33AC();
    virtual void fn_51_33A8();
    virtual void fn_51_2830();
    virtual void fn_51_33A0();
    virtual void fn_51_3394();
    virtual void fn_51_3384();
    virtual void fn_51_3374();
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
    virtual void fn_51_3370();
    virtual void fn_51_336C();
    virtual void fn_51_3364();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_51_335C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_51_1918();
    virtual void fn_51_33D8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_51_33D0();
    virtual void fn_51_12FA8();
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
    virtual void fn_51_12400(float);
    virtual void fn_51_124C8(float);
    virtual void fn_51_12688(float);
    virtual void fn_51_126EC(float);
    virtual void fn_51_12814();
    virtual void fn_51_111C();
    virtual void fn_51_1124();
    virtual void fn_51_112C();
    virtual void fn_51_130DC();
    virtual void fn_51_13110();
    char pad40[0x2c];
    unsigned char visible : 1;
    unsigned char unused1 : 1;
    unsigned char collision : 1;
    unsigned char unused2 : 3;
    unsigned char dirty : 1;
    unsigned char unused3 : 1;
    char pad6d[0x5b];
    unsigned char enabled;
    char padc9[0x93];
    unsigned char* trigger;
    unsigned char* state;
};
extern "C" void fn_51_28F4();
extern "C" void fn_51_12248(GroundView* self, float delta) {
    fn_51_28F4();
    if (self->enabled) {
        if (self->state) {
            switch (*self->state) {
            case 0:
                if (self->visible == 1)
                    self->setVisibility(0);
                if (self->collision == 1)
                    ((Ground*)self)->setEnableCollisionStatus(false);
                self->fn_51_13110();
                break;
            case 1:
                if (*self->trigger <= 1) {
                    if (!self->visible)
                        self->setVisibility(1);
                    if (*self->trigger != 0) {
                        if (!self->collision) {
                            ((Ground*)self)->setEnableCollisionStatus(true);
                            self->updateG3dProcCalcWorld();
                            self->dirty = 0;
                        }
                        self->fn_51_130DC();
                    }
                }
                break;
            }
        }
        self->fn_51_12400(delta);
        self->fn_51_12688(delta);
        self->fn_51_126EC(delta);
        self->fn_51_124C8(delta);
    }
}
