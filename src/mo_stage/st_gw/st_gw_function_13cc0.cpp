#pragma force_active on
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>

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
    virtual void fn_63_244();
    virtual void fn_63_324();
    virtual void createObjPokeTrainer();
    virtual void fn_63_298C();
    virtual void fn_63_2988();
    virtual void fn_63_297C();
    virtual void fn_63_2974();
    virtual void fn_63_296C();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_63_31C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_63_2964();
    virtual void fn_63_295C();
    virtual void getZoneLightSetIndex();
    virtual void fn_63_2940();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_63_293C();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_63_2994();
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
    virtual void fn_63_292C();
    virtual void fn_63_2934();
    virtual void fn_63_2924();
    virtual void fn_63_291C();
    virtual void fn_63_2914();
    virtual void fn_63_2900();
    virtual void fn_63_28F0();
    virtual void fn_63_28E4();
    virtual void fn_63_28D8();
    virtual void fn_63_28D0();
    virtual void fn_63_28C8();
    virtual void fn_63_28C0();
    virtual void fn_63_28BC();
    virtual void isEnd();
    virtual void isEventEnd();
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
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_63_28B4();
    virtual void fn_63_28AC();
    virtual void fn_63_28A4();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_63_29A4();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
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
    virtual void fn_63_13BD8();
    virtual void fn_63_13C40();
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
    virtual void setNode();
    virtual void fn_63_59C();
    virtual int fn_63_3370();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_63_2D00();
    virtual void fn_63_13FA0();
    virtual void fn_63_2ED8(int, int, bool, float*);

    unsigned char pad40[0x24];
    float speed;
    unsigned char pad68[4];
    unsigned char visible : 1;
    unsigned char flags : 7;
    unsigned char pad6D[0xE3];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* trigger;
    unsigned char triggerValue;
    unsigned char pad15D[7];
    float endFrame;
    unsigned char pad168[0xC];
    unsigned char target;
    unsigned char pad175[3];
    Vec3f* positions;
    unsigned char* index;
    unsigned char pad180[4];
    unsigned char* targetPtr;
    unsigned char* mode;
    unsigned char previousIndex;
    unsigned char pad18D[3];
    snd3DGenerator sound;
};

extern "C" {
extern const float lbl_63_rodata_1B8;
extern const float lbl_63_rodata_1BC;
}

extern "C" void fn_63_13CC0(Ground* self, float delta) {
    if (self->fn_63_3370()) {
        self->timer -= delta;
        if (self->timer < lbl_63_rodata_1B8)
            self->timer = lbl_63_rodata_1B8;

        switch (self->state) {
        case 0:
            self->fn_63_2ED8(1, 0, true, 0);
            self->setVisibility(0);
            self->state = 1;
            break;
        case 1:
            if (*self->trigger == self->triggerValue)
                self->state = 3;
            break;
        case 2:
            break;
        case 3:
            if (*self->trigger != self->triggerValue) {
                if (self->target == *self->targetPtr) {
                    self->fn_63_2ED8(0, 0, false, &self->endFrame);
                    if (self->speed < lbl_63_rodata_1B8)
                        self->speed *= lbl_63_rodata_1BC;
                    self->state = 4;
                } else {
                    *self->index = 0xFF;
                    self->state = 0;
                }
            } else {
                bool show;
                switch (*self->mode) {
                case 1:
                    if (self->target == *self->targetPtr)
                        show = true;
                    else
                        show = false;
                    break;
                case 0:
                default:
                    show = false;
                    break;
                }
                if (self->visible == 1 && show == false) {
                    self->setVisibility(0);
                } else if (self->visible == 0 && show == true) {
                    self->setVisibility(1);
                }
                if (show == true && *self->index != self->previousIndex) {
                    self->sound.playSE((SndID)0x1C90, 0, 0, -1);
                    self->sound.setPos(&self->positions[*self->index]);
                }
                self->previousIndex = *self->index;
            }
            break;
        case 4:
            if (self->getMotionFrame(0) >= self->endFrame) {
                *self->index = 0xFF;
                self->state = 0;
            }
            break;
        }
    }
}
