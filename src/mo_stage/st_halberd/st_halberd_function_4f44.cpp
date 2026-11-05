#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
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
    virtual void fn_57_4E78();
    virtual void fn_57_4ED0();
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
    virtual void fn_57_3A9C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_57_638();
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978();
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
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
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio();
    virtual void fn_57_5558(float, unsigned long);
    virtual float fn_57_55E0(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_57_3AC8();
    virtual void fn_57_3AC0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_57_3AB8();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_57_650();
    virtual void fn_57_658();
    virtual void fn_57_4F44();
    virtual void fn_57_50F0();
    virtual void fn_57_51E0(int, int, int, float*);
    char pad40[0x110];
    unsigned char state;
    char pad151[7];
    float* motionFrame;
    unsigned char* event;
    char pad160[4];
    unsigned char flag;
    unsigned char mode;
    char pad166[2];
    float frame;
};

extern "C" void fn_57_4F44(Ground* self) {
    if (self->motionFrame && self->event) {
        switch (self->state) {
        case 0:
            self->fn_57_51E0(2, 0, 1, 0);
            self->state = 2;
        case 2:
            if (*self->event == 2) {
                self->fn_57_51E0(0, 0, 1, &self->frame);
                self->fn_57_5558(*self->motionFrame, 0);
                self->state = 3;
            }
            break;
        case 3:
            break;
        }
        switch (self->mode) {
        case 0:
            if (self->fn_57_55E0(0) >= self->frame) {
                self->fn_57_51E0(1, 1, 1, 0);
                self->flag = 1;
            }
            break;
        case 1:
            if (*self->event == 2) {
                self->fn_57_51E0(0, 0, 1, &self->frame);
                self->fn_57_5558(*self->motionFrame, 0);
            }
            break;
        }
    }
}
