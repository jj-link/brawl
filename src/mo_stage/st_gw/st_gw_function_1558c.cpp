#pragma force_active on

struct Ground_base {
    char pad[0x3c];
};

struct GwParam {
    char pad[0x3c];
    float value;
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
    virtual void fn_63_15534();
    virtual void fn_63_1558C();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void fn_63_15BB4();
    virtual void fn_63_59C();
    virtual GwParam* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition(void*, unsigned long, unsigned long);
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
    virtual float getMotionFrame(unsigned long);
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
    virtual void fn_63_2D00();
    virtual void fn_63_2E10();
    virtual void fn_63_2ED8(int, int, int, float*);
    virtual void fn_63_8FC();
    virtual void fn_63_904();
    virtual void fn_63_15848(float);

    char pad40[0x24];
    float speed;
    char pad68[0xe8];
    unsigned char state;
    char pad151[3];
    float timer;
    unsigned char* trigger;
    unsigned char triggerValue;
    char pad15d[7];
    float endFrame;
    char pad168[0xc];
    unsigned long node;
    unsigned long nodes[3];
    void* position;
    unsigned char* index;
    char pad18c[4];
    unsigned char* flag;
    unsigned char previousFlag;
};

extern "C" {
void fn_63_2C98(Ground*, float);
extern const float lbl_63_rodata_1E0;
extern const float lbl_63_rodata_1E4;

void fn_63_1558C(Ground* self, float delta) {
    fn_63_2C98(self, delta);
    GwParam* param = self->fn_63_3370();
    if (param != 0) {
        self->timer -= delta;
        if (self->timer < lbl_63_rodata_1E0)
            self->timer = lbl_63_rodata_1E0;

        switch (self->state) {
        case 0:
            self->fn_63_2ED8(1, 0, 1, 0);
            self->setVisibility(0);
            self->setNodeVisibility(false, 0, self->node, true, true);
            self->previousFlag = 1;
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == self->triggerValue) {
                self->setVisibility(1);
                if (*self->index == 0xff)
                    *self->index = 0;
                self->timer = param->value;
                self->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            if (*self->trigger != self->triggerValue) {
                self->fn_63_2ED8(0, 0, 1, &self->endFrame);
                if (self->speed < lbl_63_rodata_1E0)
                    self->speed *= lbl_63_rodata_1E4;
                self->state = 4;
            } else {
                if (*self->flag == 0)
                    self->fn_63_15848(delta);
                else if (*self->flag != self->previousFlag)
                    self->setNodeVisibility(false, 0, self->node, true, true);
                self->getNodePosition(self->position, 0, self->nodes[*self->index]);
                self->previousFlag = *self->flag;
            }
            break;
        case 4:
            if (self->getMotionFrame(0) >= self->endFrame)
                self->state = 0;
            break;
        }
    }
}
}
