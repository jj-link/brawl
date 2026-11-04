#pragma force_active on
extern "C" const float lbl_78_rodata_0;
extern "C" float randf__Fv();
struct Params { char pad[0x24]; float initial, repeat; char pad2[0x10]; float chance; };
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
    virtual void fn_78_E3C();
    virtual void setCameraLimitRange();
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
    virtual void fn_78_F78();
    virtual void fn_78_FD4();
    virtual void fn_78_1128();
    virtual void fn_78_1210();
    virtual unsigned int fn_78_1214(int);
    char pad40[0x9c-0x40];
    Params* params;
    char padA0[0x250-0xa0];
    unsigned char state;
    char pad251[3];
    float timer;
    unsigned char motion;
    char pad259[0x268-0x259];
    unsigned int flags : 3;
    unsigned int other : 29;
};
extern "C" void fn_78_FD4(Stage* self, float delta) {
    Params* p = self->params;
    if (p) {
        self->timer -= delta;
        if (self->timer < lbl_78_rodata_0)
            self->timer = lbl_78_rodata_0;
        switch (self->state) {
        case 0:
            self->timer = p->initial;
            self->state = 1;
            break;
        case 1:
            if (lbl_78_rodata_0 == self->timer) {
                self->timer = p->repeat;
                self->state = 2;
            }
            break;
        case 2:
            if (lbl_78_rodata_0 == self->timer && self->fn_78_1214(0) == 1)
                self->state = 3;
            break;
        case 3:
            if (self->motion == 4) {
                self->timer = p->initial;
                self->state = 1;
                self->flags = 1;
                if (randf__Fv() < p->chance)
                    self->fn_78_1214(1);
            }
            break;
        }
    }
}