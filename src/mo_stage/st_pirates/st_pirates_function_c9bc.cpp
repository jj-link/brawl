#pragma force_active on
extern "C" const float lbl_52_rodata_1E8;
extern "C" const float lbl_52_rodata_1EC;
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_52_C7B8();
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
    virtual void fn_52_C760();
    virtual void fn_52_C928();
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
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8();
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
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
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, unsigned long);
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_52_3694();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_52_3718();
    virtual void fn_52_3710();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_52_3708();
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
    virtual void fn_52_864();
    virtual void fn_52_A24();
    virtual void fn_52_C9BC();
    virtual void fn_52_CB7C(int, int, int, float*);
    unsigned char pad40[0x110];
    unsigned char state;
    unsigned char pad151[7];
    float* ref158;
    unsigned char pad15c[4];
    unsigned char flag160;
    unsigned char pad161[7];
    unsigned char* command;
    unsigned char saved16c;
    unsigned char flag16d;
    unsigned char pad16e[2];
    float timer;
};
extern "C" void fn_52_C9BC(Ground* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_52_rodata_1E8)
        self->timer = lbl_52_rodata_1E8;
    switch ((int)self->state) {
    case 0:
        self->fn_52_CB7C(1, 0, 1, 0);
        self->setVisibility(0);
        self->state = 1;
        break;
    case 1:
        if (self->flag160 == 1) {
            unsigned int mode = 1;
            int changed = 1;
            switch (self->flag16d) {
            case 0:
                mode = 1;
                break;
            }
            if (*self->command != self->saved16c) {
                unsigned char old = mode;
                switch (*self->command) {
                case 7:
                    mode = 0;
                    self->setVisibility(1);
                    break;
                default:
                    mode = 1;
                    self->setVisibility(0);
                    break;
                }
                if (mode != old)
                    changed = 0;
                self->saved16c = *self->command;
            }
            if (mode != 1) {
                self->fn_52_CB7C(mode, changed, 1, &self->timer);
                self->setMotionFrame(lbl_52_rodata_1EC - *self->ref158, 0);
            }
        }
        break;
    }
}
