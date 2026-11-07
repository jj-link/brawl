#pragma force_active on
#include <gm/gm_global.h>
#include <mt/mt_prng.h>
extern "C" const float lbl_71_rodata_0;
extern "C" const float lbl_71_rodata_34;
struct Params { char pad[0x3c]; float a,b,c,d; };
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
    virtual void fn_71_1D08();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_71_1EC();
    virtual void fn_71_284();
    virtual void createObjPokeTrainer();
    virtual void fn_71_24E4();
    virtual void fn_71_24E0();
    virtual void fn_71_24D4();
    virtual void fn_71_24CC();
    virtual void fn_71_24C4();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_71_27C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_71_24BC();
    virtual void fn_71_24B4();
    virtual void getZoneLightSetIndex();
    virtual void fn_71_2498();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_71_2494();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_71_24EC();
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
    virtual void fn_71_2484();
    virtual void fn_71_248C();
    virtual void fn_71_247C();
    virtual void fn_71_2474();
    virtual void fn_71_246C();
    virtual void fn_71_2458();
    virtual void fn_71_2448();
    virtual void fn_71_243C();
    virtual void fn_71_2430();
    virtual void fn_71_2428();
    virtual void fn_71_2420();
    virtual void fn_71_2060();
    virtual void fn_71_241C();
    virtual void isEnd();
    virtual void fn_71_2358();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void fn_71_215C();
    virtual void setAppearKind();
    virtual void fn_71_22EC();
    virtual void fn_71_2510();
    virtual void fn_71_23CC();
    virtual void fn_71_2504();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_71_2414();
    virtual void fn_71_240C();
    virtual void fn_71_2404();
    virtual void fn_71_23B8();
    virtual void fn_71_2348();
    virtual void getMadeinAiData();
    virtual void fn_71_24FC();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void fn_71_2150();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_71_23FC();
    virtual void fn_71_23F4();
    virtual void fn_71_23F0();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_71_24F4();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_71_1428();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_71_77C();
    virtual void fn_71_87C();
    virtual void fn_71_98C();
    virtual void fn_71_B4C();
    virtual void fn_71_C78();
    virtual void fn_71_D34();
    virtual void fn_71_F14();
    virtual void fn_71_FD4();
    virtual void fn_71_123C();
    virtual void fn_71_1358();
    virtual void fn_71_14CC();
    virtual void fn_71_1528();
    virtual void fn_71_1670();
    virtual void fn_71_18B0();
    virtual void fn_71_1AF4();
    virtual unsigned int fn_71_1DA0();
    char pad2[0x9c-0x40];
    Params* params;
    char pad3[0x294-0xa0];
    unsigned char flag, mode, pad4, state;
    float timer, value, value2;
    unsigned char type, motion;
};
extern "C" void fn_71_1528(Stage* self, float delta) {
    if (self->type != 9 && g_GameGlobal->m_modeMelee != 0) {
        Params* p = self->params;
        if (p) {
            self->timer -= delta;
            if (self->timer < lbl_71_rodata_0)
                self->timer = lbl_71_rodata_0;
            switch (self->state) {
            case 0:
                self->value2 = p->a + (p->b - p->a) * randf();
                self->value = p->c + (p->d - p->c) * randf();
                self->state = 1;
                break;
            case 1:
                if (self->flag && lbl_71_rodata_0 == self->timer) {
                    if (self->fn_71_1DA0() == 1) {
                        self->motion = 4;
                        self->mode = 0;
                        self->state = 5;
                    }
                    self->timer = lbl_71_rodata_34;
                }
                break;
            case 5:
                break;
            }
        }
    }
}