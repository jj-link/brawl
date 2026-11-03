#pragma force_active on
extern "C" const float lbl_54_rodata_100;

struct Sub {
    char pad[0x50];
    float f50;
    float f54;
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
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
    virtual void fn_54_1EC();
    virtual void fn_54_2FC();
    virtual void createObjPokeTrainer();
    virtual void fn_54_2AE0();
    virtual void fn_54_2ADC();
    virtual void fn_54_2AD0();
    virtual void fn_54_2AC8();
    virtual void fn_54_2AC0();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_54_2F4();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_54_2AB8();
    virtual void fn_54_2AB0();
    virtual void getZoneLightSetIndex();
    virtual void fn_54_2A94();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_54_2A90();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_54_2AE8();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void fn_54_2A80();
    virtual void fn_54_2A88();
    virtual void fn_54_2A78();
    virtual void fn_54_2A70();
    virtual void fn_54_2A68();
    virtual void fn_54_2A54();
    virtual void fn_54_2A44();
    virtual void fn_54_2A38();
    virtual void fn_54_2A2C();
    virtual void fn_54_2A24();
    virtual void fn_54_2A1C();
    virtual void fn_54_2864();
    virtual void fn_54_2A18();
    virtual void isEnd();
    virtual void fn_54_2900();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void startAppear();
    virtual void setAppearKind();
    virtual void endAppear();
    virtual void getAppearTask();
    virtual void forceStopAppear();
    virtual void fn_54_2B00();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_54_2A10();
    virtual void fn_54_2A08();
    virtual void fn_54_2A00();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_54_2AF8();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_54_29F8();
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
    virtual void fn_54_C170();
    virtual void fn_54_C1C8();
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
    virtual void fn_54_338C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_54_1310();
    virtual Sub* fn_54_3150();
    virtual void fn_54_3388();
    virtual void fn_54_2C40();
    virtual void fn_54_3380();
    virtual void fn_54_3374();
    virtual void fn_54_3364();
    virtual void fn_54_3354();
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
    virtual void fn_54_3350();
    virtual void fn_54_334C();
    virtual void fn_54_3344();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_54_333C();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_54_33B8();
    virtual void fn_54_33B0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_54_33A8();
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
    virtual void fn_54_1510();
    virtual void fn_54_C23C(float);
    virtual void fn_54_C458();
    virtual void fn_54_C510(int, int, int, float*);
    char pad40[0x2c];
    unsigned char visible : 1;
    unsigned char flags : 7;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    unsigned char* trigger;
    char pad15c[0xc];
    float end;
};

extern "C" void fn_54_C23C(Ground* self, float delta) {
    Sub* sub = self->fn_54_3150();
    if (sub) {
        self->timer -= delta;
        if (self->timer < lbl_54_rodata_100)
            self->timer = lbl_54_rodata_100;
        self->end -= delta;
        if (self->end < lbl_54_rodata_100)
            self->end = lbl_54_rodata_100;
        switch (self->state) {
        case 0:
            self->fn_54_C510(2, 0, 1, 0);
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == 4) {
                self->timer = sub->f50;
                self->state = 6;
            }
            break;
        case 6:
            if (lbl_54_rodata_100 == self->timer) {
                self->fn_54_C510(0, 0, 1, &self->end);
                self->state = 7;
            }
            break;
        case 7:
            if (!self->visible)
                self->setVisibility(1);
            if (*self->trigger != 4) {
                self->timer = sub->f54;
                self->state = 8;
            }
            break;
        case 8:
            if (lbl_54_rodata_100 == self->timer) {
                self->fn_54_C510(1, 0, 1, &self->end);
                self->state = 9;
            }
            break;
        case 9:
            if (lbl_54_rodata_100 == self->end)
                self->state = 0;
            break;
        }
    }
}
