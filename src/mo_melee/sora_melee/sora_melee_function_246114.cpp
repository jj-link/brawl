#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void processAnim();
    virtual void slot3();
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
    virtual void slot22();
    virtual void slot23();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void slot31();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void slot38();
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
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void slot69();
    virtual void getBgmID();
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
    virtual void slot94();
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
    virtual void slot107();
    virtual void getBamperVector();
    virtual void slot109();
    virtual void slot110();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual u32 helperStarWarp(int arg);
};

struct Sub50 { char pad[0x48]; u32 unk48; };

struct Self {
    char pad0[0x50];
    Sub50* unk50;
    u8 unk54;
    char pad55[7];
    s32 unk5C;
};

struct UnkParam {
    union {
        bool asBool;
        u32 asInt;
    } unk0;
    s32 unk4;
};

extern Object_vptr_3c* lbl_27_bss_5668;

inline bool checkState() {
    gmAdvData* data = g_GameGlobal->m_advData;
    if (data) {
        unsigned char state = *((unsigned char*)data + 0x604);
        if (state == 1U || (unsigned int)state == 2U || (int)state == 3U)
            return true;
    }
    return false;
}

extern "C" void fn_27_246114(Self* self) {
    UnkParam p20;
    UnkParam p18;
    UnkParam p10;
    gfPadStatus status;

    gmAdvData* adv = g_GameGlobal->m_advData;
    if (adv != NULL) {
        p18.unk0.asInt = *(u32*)&adv->unk4930[0];
        p18.unk4 = *(s32*)&adv->unk4930[4];
    } else {
        p20.unk0.asBool = false;
        p20.unk4 = -1;
        p18 = p20;
    }
    p10 = p18;

    if (p10.unk4 != -1 && (((u32)((u8*)adv)[0x606] >> 7 & 1U) == 1U)) {
        g_gfPadSystem->getGamePadStatus(p10.unk4, &status);
        if (self->unk54 != 0) {
            if (status.m_buttonsPressedThisFrame.bits & GF_PAD_BUTTON_BIT_START) {
                gmAdvData* a = g_GameGlobal->m_advData;
                if (!checkState() && !((((u8*)a)[0x4924] >> 7) & 1) && self->unk50->unk48 == 1 &&
                    lbl_27_bss_5668 != NULL && lbl_27_bss_5668->helperStarWarp(1) == 1) {
                    self->unk54 = 0;
                }
            }
        } else {
            s32 cnt = self->unk5C + 1;
            self->unk5C = cnt;
            if (cnt >= 0x3c) {
                self->unk5C = 0;
                self->unk54 = 1;
            }
        }
    }
}
