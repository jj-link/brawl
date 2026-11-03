#pragma force_active on

struct Ground_base {
    char pad[0x3c];
};

struct GreenHillCollision {
    char pad[0x52];
    unsigned short flags;
};

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
    virtual void fn_72_9F5C();
    virtual void fn_72_A04C();
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
    virtual void fn_72_1A98();
    virtual void startup();
    virtual void fn_72_A918();
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
    virtual void fn_72_1A54();
    virtual void fn_72_1A50();
    virtual void fn_72_1A48();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
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
    virtual void fn_72_BB5C();
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
    virtual void fn_72_A0D8();
    virtual void fn_72_A174();
    virtual void fn_72_A3B4();
    virtual void fn_72_A9D0();

    char pad040[0x10c];
    int field14c;
    char pad150[0x18];
    unsigned char* field168;
    unsigned char field16c;
    char pad16d[0x0f];
    unsigned long field17c;
    unsigned long field180;
    char pad184[4];
    GreenHillCollision* field188;
    unsigned char field18c;
};

extern "C" void fn_72_A174(Ground* self) {
    if (self->field18c == 1) {
        if (self->field188 != 0) {
            unsigned short flags = 0;
            switch (self->field16c) {
            case 0:
                if (self->field168[1] == 1) {
                    self->setNodeVisibility(true, 0, self->field17c, true, false);
                } else {
                    self->setNodeVisibility(false, 0, self->field17c, true, false);
                    flags |= 0x2000;
                }
                if (self->field168[2] == 1) {
                    self->setNodeVisibility(true, 0, self->field180, true, false);
                } else {
                    self->setNodeVisibility(false, 0, self->field180, true, false);
                    flags |= 0x4000;
                }
                break;
            case 1:
                if (self->field168[0] == 1) {
                    self->setNodeVisibility(true, 0, self->field17c, true, false);
                } else {
                    self->setNodeVisibility(false, 0, self->field17c, true, false);
                    flags |= 0x4000;
                }
                break;
            case 2:
                if (self->field168[0] == 1) {
                    self->setNodeVisibility(true, 0, self->field17c, true, false);
                } else {
                    self->setNodeVisibility(false, 0, self->field17c, true, false);
                    flags |= 0x2000;
                }
                break;
            }
            self->field188->flags = flags;
        }
    } else {
        self->fn_72_A9D0();
        if (self->field14c != 0) {
            self->field18c = 1;
        }
    }
}
