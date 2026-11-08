#pragma force_active on

struct IceData {
    char pad[0xc];
    float field_c;
};

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
    virtual void fn_62_8E60();
    virtual void fn_62_8F50();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping(unsigned long);
    virtual void setVisibilityAttachedEffect(unsigned long);
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup();
    virtual void setNode();
    virtual void fn_62_A44();
    virtual IceData* fn_62_310C();
    virtual void fn_62_3108();
    virtual void fn_62_2C7C();
    virtual void fn_62_3100();
    virtual void fn_62_30F4();
    virtual void fn_62_30E4();
    virtual void fn_62_30D4();
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
    virtual void fn_62_30D0();
    virtual void fn_62_30CC();
    virtual void fn_62_30C4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_62_30BC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_62_3140();
    virtual void fn_62_3138();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_62_3130();
    virtual void fn_62_9ABC();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit(unsigned long, unsigned long);
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
    virtual void fn_62_905C();
    virtual void fn_62_9138();
    virtual void fn_62_9210();
    virtual void fn_62_931C();
    virtual void fn_62_94B0();

    char pad40[0x10c];
    int field14c;
    char pad150[4];
    float field154;
    char pad158[0xc];
    float field164;
    char pad168[0x10];
    unsigned char state;
};

extern "C" {
extern const float lbl_62_rodata_F8;
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
}

extern "C" void fn_62_905C(Ground* self) {
    if (self->state == 1) {
        if (lbl_62_rodata_F8 == self->field164 && lbl_62_rodata_F8 == self->field154) {
            IceData* data = self->fn_62_310C();
            if (data) {
                self->field164 = data->field_c;
                self->setVisibility(1);
                setEnableCollisionStatus__6GroundFb(self, true);
                self->enableHit(0, 0);
            }
        }
    } else {
        self->fn_62_94B0();
        if (self->field14c != 0) {
            self->state = 1;
        }
    }
}