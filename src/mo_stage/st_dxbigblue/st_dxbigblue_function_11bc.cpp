#include <types.h>
#pragma force_active on

extern "C" float randf__Fv();

struct Stage_base {
    char pad[0x3c];
};

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
    virtual void fn_81_570();
    virtual void fn_81_620();
    virtual void createObjPokeTrainer();
    virtual void fn_81_4050();
    virtual void fn_81_404C();
    virtual void fn_81_4040();
    virtual void fn_81_4038();
    virtual void fn_81_4030();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_81_618();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_81_4028();
    virtual void fn_81_4020();
    virtual void getZoneLightSetIndex();
    virtual void fn_81_4004();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_81_4000();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_81_4058();
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
    virtual void fn_81_3FF0();
    virtual void fn_81_3FF8();
    virtual void fn_81_3FE8();
    virtual void fn_81_3FE0();
    virtual void fn_81_3FD8();
    virtual void fn_81_3FC4();
    virtual void fn_81_3FB4();
    virtual void fn_81_3FA8();
    virtual void fn_81_3F9C();
    virtual void fn_81_3F94();
    virtual void fn_81_3F8C();
    virtual void fn_81_3F84();
    virtual void fn_81_3F80();
    virtual void isEnd();
    virtual void fn_81_3F40();
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
    virtual void fn_81_3F78();
    virtual void fn_81_3F70();
    virtual void fn_81_3F68();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void isBamperVector();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_81_3F60();
    virtual void fn_81_3F58();
    virtual void fn_81_3F54();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_81_4060();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_81_1498();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_81_984();
    virtual void fn_81_ABC();
    virtual void fn_81_C04();
    virtual void fn_81_D20();
    virtual void fn_81_DFC();
    virtual void fn_81_ED8();
    virtual void fn_81_11BC();
    virtual void fn_81_130C(unsigned char);

    char padArr[0xa3c];
    unsigned char arr[30];
};

extern "C" void fn_81_11BC(Stage* self) {
        int pick;
    int n = 29;
    int i = 0;
    for (int c = 5; c != 0; c--) {
        self->arr[(u8)i] = i;
        self->arr[(u8)i + 1] = i + 1;
        self->arr[(u8)i + 2] = i + 2;
        self->arr[(u8)i + 3] = i + 3;
        self->arr[(u8)i + 4] = i + 4;
        self->arr[(u8)i + 5] = i + 5;
        i += 6;
    }
    for (u8 k = 0; k < 30; k++) {
        int j = (int)((f32)n * randf__Fv());
        unsigned int m = (u8)j ? j : 0;
        pick = 29;
        if ((u8)m < 29) {
            pick = m;
        }
        u8 tmp = self->arr[k];
        self->arr[k] = self->arr[(u8)pick];
        self->arr[(u8)pick] = tmp;
    }
    for (n = 0; (unsigned int)n < 30; n++) {
        self->fn_81_130C((u8)n);
    }
}
