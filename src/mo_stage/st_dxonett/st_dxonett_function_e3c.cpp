#include <cm/cm_camera_controller.h>
#include <types.h>

#pragma force_active on

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
    virtual void fn_78_1A8();
    virtual void fn_78_250();
    virtual void createObjPokeTrainer();
    virtual void fn_78_1554();
    virtual void fn_78_1550();
    virtual void fn_78_1544();
    virtual void fn_78_153C();
    virtual void fn_78_1534();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_78_248();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_78_152C();
    virtual void fn_78_1524();
    virtual void getZoneLightSetIndex();
    virtual void fn_78_1508();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_78_1504();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_78_155C();
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
    virtual void fn_78_14F4();
    virtual void fn_78_14FC();
    virtual void fn_78_14EC();
    virtual void fn_78_14E4();
    virtual void fn_78_14DC();
    virtual void fn_78_14C8();
    virtual void fn_78_14B8();
    virtual void fn_78_14AC();
    virtual void fn_78_14A0();
    virtual void fn_78_1498();
    virtual void fn_78_1490();
    virtual void fn_78_1488();
    virtual void fn_78_1484();
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
    virtual void fn_78_147C();
    virtual void fn_78_1474();
    virtual void fn_78_146C();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_78_156C();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_78_1464();
    virtual void fn_78_145C();
    virtual void fn_78_1458();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_78_1564();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_78_E3C(float);
    virtual void setCameraLimitRange(float, float, float, float);
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_78_594();
    virtual void fn_78_4E0();
    virtual void fn_78_680();
    virtual void fn_78_7E8();
    virtual void fn_78_8E8();
    virtual void fn_78_AE8();
    virtual void fn_78_BEC();
    virtual void fn_78_CD0();
    virtual void fn_78_F78(float);
    virtual void fn_78_FD4(float);
    virtual void fn_78_1128(float);
    virtual void fn_78_1210(float);

    u8 pad_40[0xEB - 0x40];
    u8 unkEB;
};

extern "C" const float lbl_78_rodata_0[];
extern "C" float fn_8016232C(float);
extern "C" float fn_801622C4(float);

extern "C" void fn_78_E3C(Stage* self, float farg0) {
    const float* c = lbl_78_rodata_0;
    if (self->unkEB == 1) {
        char* p = (char*)CameraController::getInstance() + 0x84;
        float f4;
        if (p != 0) {
            float f31 = fn_8016232C(c[8]);
            float f2 = fn_801622C4(c[8]) / f31;
            float f1 = *(float*)(p + 0x10) * f2;
            f4 = -(c[9] * f1);
        }
        self->setCameraLimitRange(c[10], c[11], c[12], f4);
    } else {
        self->resetCameraLimitRange();
    }
    self->fn_78_F78(farg0);
    self->fn_78_FD4(farg0);
    self->fn_78_1128(farg0);
    self->fn_78_1210(farg0);
}
