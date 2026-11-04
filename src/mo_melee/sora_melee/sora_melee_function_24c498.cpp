#include <snd/snd_system.h>
#include <if/if_mngr.h>
#pragma force_active on

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
    virtual ~Stage();
    virtual void createObj();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void loading();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void getAIRange();
    virtual void getDefaultLightSetIndex();
    virtual void getZoneLightSetIndex();
    virtual void getScrollDir();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void appearanceFighterLocal();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void isReStartSamePoint();
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
    virtual void getBgmID();
    virtual void getBgmID_2();
    virtual void getNowStepBgmID();
    virtual void getBgmOptionID();
    virtual void isBgmChange();
    virtual void getBgmChangeID();
    virtual void setBgmChange();
    virtual void getBgmVolume();
    virtual void getBgmPlayOffsetFrame();
    virtual void isNextStepBgmEqualNowStepBgmFromFlag();
    virtual void setFrameRuleTime();
    virtual void getFrameRuleTime();
    virtual void notifyTimmingGameStart();
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
    virtual void isCameraLocked();
    virtual void isBossBattleMode();
    virtual void isSimpleBossBattleMode();
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
    virtual void helperStarWarp();
    virtual void initializeFighterAttackRatio();
    virtual void startFighterEvent();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void getWind2ndOnlyData();
    virtual void updateWind2ndOnly();
    virtual void setVision(unsigned char);
};

extern Stage* lbl_27_bss_5668;
extern "C" void fn_800DE508(void*, int);
extern "C" void fn_800765B0(sndSystem*, void*, int);

struct Object {
    char pad[0xac];
    void* sound;
    char pad2[0x2d];
    unsigned char flag;
};

extern "C" void fn_27_24C498(Object* self, int kind, int alternate) {
    sndSystem* system;
    int sound = 0;
    int voice = 0;
    switch (kind) {
    case 0:
        if (g_IfMngr) fn_800DE508(g_IfMngr->m_ifCenter, 4);
        lbl_27_bss_5668->setVision(9);
        sound = 0x1fdc;
        break;
    case 1:
        if (g_IfMngr) fn_800DE508(g_IfMngr->m_ifCenter, 7);
        lbl_27_bss_5668->setVision(12);
        sound = 0x1fd9;
        voice = 30;
        break;
    case 2:
        if (g_IfMngr) fn_800DE508(g_IfMngr->m_ifCenter, 5);
        lbl_27_bss_5668->setVision(10);
        sound = 0x1fd7;
        voice = 30;
        break;
    case 3:
        lbl_27_bss_5668->setVision(11);
        if (g_IfMngr) fn_800DE508(g_IfMngr->m_ifCenter, 8);
        sound = 0x1fd8;
        voice = 32;
        break;
    case 4:
        lbl_27_bss_5668->setVision(19);
        if (g_IfMngr) fn_800DE508(g_IfMngr->m_ifCenter, 9);
        sound = 0x1fd6;
        voice = 30;
        break;
    case 5:
        break;
    }
    if (sound != 0) {
        fn_800765B0(g_sndSystem, self->sound, 0);
        system = g_sndSystem;
        int id = 0x1fd2;
        if (!alternate) id = sound;
        system->playSE((SndID)id, -1, 0, 0, -1);
    }
    if (self->flag && voice != 0) {
        system = g_sndSystem;
        int id = 0x1a;
        if (!alternate) id = voice;
        system->playSE((SndID)id, -1, 0, 0, -1);
    }
}