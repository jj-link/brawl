#pragma force_active on
struct Ground_base { char pad[0x3c]; };

struct GroundEvent {
    unsigned char state;
    char pad1[0x33];
    float value;
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_72_C6F4();
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
    virtual void fn_72_C69C();
    virtual void fn_72_C74C();
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
    virtual void fn_72_1A98();
    virtual void startup();
    virtual void fn_72_C8D4();
    virtual void fn_72_468();
    virtual void fn_72_1A90();
    virtual void fn_72_1A8C();
    virtual void fn_72_1128();
    virtual void fn_72_1A84();
    virtual void fn_72_1A78();
    virtual void fn_72_1A68();
    virtual void fn_72_1A58();
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
    virtual void fn_72_1A54();
    virtual void fn_72_1A50();
    virtual void fn_72_1A48();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_72_1A40();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_72_1AC4();
    virtual void fn_72_1ABC();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_72_1AB4();
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
    virtual void fn_72_C7A8();
    virtual void fn_72_C928(int, int, int, float*);

    char pad40[0x24];
    float unk64;
    char pad68[0xE8];
    unsigned char state;
    char pad151[7];
    GroundEvent* event;
    char pad15c[8];
    float frame;
};

extern "C" void fn_72_C7A8(Ground* self) {
    switch (self->state) {
    case 0:
        self->fn_72_C928(1, 0, 1, 0);
        self->setVisibility(0);
        self->state = 1;
    case 1:
        if (self->event->state == 3) {
            self->fn_72_C928(0, 0, 1, &self->frame);
            self->setVisibility(1);
            self->state = 8;
        }
        break;
    case 8:
        self->unk64 = self->event->value;
        if (self->getMotionFrame(0) >= self->frame) {
            self->event->state = 5;
            self->state = 0;
        }
        break;
    }
}
