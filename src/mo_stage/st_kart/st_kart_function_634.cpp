#pragma force_active on

typedef unsigned char u8;
typedef signed short s16;

struct Sub {
    char pad[0x30];
    u8 count;
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
    virtual void fn_49_E58();
    virtual void init();
    virtual void fn_49_12C();
    virtual void fn_49_1A0();
    virtual void createObjPokeTrainer();
    virtual void fn_49_11A0();
    virtual void fn_49_119C();
    virtual void fn_49_1190();
    virtual void fn_49_1188();
    virtual void fn_49_1180();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_49_198();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_49_1178();
    virtual void fn_49_1170();
    virtual void fn_49_E5C();
    virtual void fn_49_1154();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_49_1150();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_49_11A8();
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
    virtual void fn_49_1140();
    virtual void fn_49_1148();
    virtual void fn_49_1138();
    virtual void fn_49_1130();
    virtual void fn_49_1128();
    virtual void fn_49_1114();
    virtual void fn_49_1104();
    virtual void fn_49_10F8();
    virtual void fn_49_10EC();
    virtual void fn_49_10E4();
    virtual void fn_49_10DC();
    virtual void fn_49_10D4();
    virtual void fn_49_10D0();
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
    virtual void fn_49_10C8();
    virtual void fn_49_10C0();
    virtual void fn_49_10B8();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_49_11B8();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_49_10B0();
    virtual void fn_49_10A8();
    virtual void fn_49_10A4();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_49_11B0();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_49_A8C();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_49_37C();
    virtual void fn_49_3E8();
    virtual void fn_49_4BC();
    virtual void fn_49_568();
    virtual void fn_49_634();
    virtual void fn_49_720(u8 i, s16 t);
    virtual void fn_49_850(u8 i, int v);
    virtual void fn_49_91C(u8 i, s16 v);

    char pad2[0x5c];
    Sub* sub;
};

extern "C" void fn_49_634(Stage* self) {
    Sub* s = self->sub;
    if (s != 0) {
        u8 i;
        u8 n;
        s16 t;
        if (s->count > 8U) {
            s->count = 8;
        }
        n = s->count;
        t = 1;
        i = 0;
        while (i != n) {
            self->fn_49_720(i, t);
            self->fn_49_850(i, 0x28);
            self->fn_49_91C(i, t + 10);
            t++;
            if (t == 5) {
                t = 1;
            }
            i++;
        }
    }
}
