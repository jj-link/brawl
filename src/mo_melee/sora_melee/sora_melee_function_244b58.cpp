#include <types.h>
#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#include <ip/ip_padconfig.h>
#include <ft/ft_manager.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

struct StageData {
    char pad[0x22];
    unsigned short value;
};

struct Object_vptr_3c_base {
    char pad[0x3c];
};

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
    virtual int getPokeTrainerPointNum();
    virtual int getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void slot31();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac(int);
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual StageData* renderDebugPositions();
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
    virtual void helperStarWarp();
    virtual void initializeFighterAttackRatio(int, float);
};

struct MeleeObject {
    char pad[0x48];
    int state;
    Object_vptr_3c* stage;
    unsigned char enabled;
};

struct AdventureData {
    char pad0[0x5fa];
    signed char count;
    char pad5fb[6];
    unsigned char name;
    char pad602;
    unsigned char mode;
    char pad604[2];
    union {
        unsigned char flags606;
        struct {
            unsigned char flag60680 : 1;
            unsigned char flags606rest : 7;
        };
    };
    char pad607[0x4924 - 0x607];
    union {
        unsigned char flags4924;
        struct {
            unsigned char flag80 : 1;
            unsigned char flag40 : 1;
            unsigned char flag20 : 1;
            unsigned char flag10 : 1;
            unsigned char flag08 : 1;
            unsigned char flag04 : 1;
            unsigned char flag02 : 1;
            unsigned char flag01 : 1;
        };
    };
    char pad4925[7];
    int excludedPad;
    unsigned char controllerType;
    char pad4931[3];
    int selectedPad;
    char pad4938[8];
    u64 time;
};

struct ModeData {
    char pad0[0xb3];
    union {
        unsigned char flagsB3;
        struct {
            unsigned char padB3bit : 1;
            unsigned char rumbleB3 : 1;
            unsigned char restB3 : 6;
        };
    };
    char padB4[0x5b];
    union {
        unsigned char flags10f;
        struct {
            unsigned char pad10fbit : 1;
            unsigned char rumble10f : 1;
            unsigned char rest10f : 6;
        };
    };
};

struct AdvManager {
    char pad0[0x48];
    union {
        unsigned char flags;
        struct {
            unsigned char padFlag : 1;
            unsigned char flag40 : 1;
            unsigned char otherFlags : 6;
        };
    };
    char pad49[0x9f];
    void* fieldE8;
    char padEC[0x18];
    void* field104;
};

extern "C" {
bool fn_27_241F14(MeleeObject*);
int fn_27_241F00(MeleeObject*);
void fn_27_245178(MeleeObject*, int);
int fn_27_23AC10(Object_vptr_3c*);
void fn_8004DA50(void*);
void* fn_8004DA80(GameGlobal*, int);
int fn_8004D9A8(GameGlobal*, int);
void fn_8004A2C8(ipPadConfig*, int, int, void*);
void fn_8004A5D8(ipPadConfig*);
int fn_800DFC68();
void fn_8010C0C4(void*, int);
void fn_8010C0DC(void*, int);
void fn_27_10A128(ftManager*, int, int);
void maskMotor__11gfPadSystemFUs(gfPadSystem*, int);

extern AdvManager* g_IfAdvMngr;
extern Object_vptr_3c* lbl_27_bss_5668;
extern const float lbl_27_rodata_3F2C;
}

extern "C" void fn_27_244B58(MeleeObject* self) {
    if (fn_27_241F14(self) == 0) {
        switch (fn_27_241F00(self)) {
        case 0: {
            AdventureData* adv = (AdventureData*)g_GameGlobal->m_advData;
            AdventureData* current;

            switch (self->state) {
            case 0:
                break;

            case 1:
                if ((adv->flag80 | adv->flag40) == 0 &&
                    !adv->flag60680 && adv->count >= 1) {
                    for (int i = 0; i < 8; ++i) {
                        if (i != ((AdventureData*)g_GameGlobal->m_advData)->excludedPad) {
                            gfPadStatus status;
                            g_gfPadSystem->getSysPadStatus(i, &status);
                            if ((status.m_buttonsCurrentFrame2.bits & 0x1000) &&
                                self->enabled && !adv->flag04) {
                                AdventureData* cur =
                                    (AdventureData*)g_GameGlobal->m_advData;
                                if (cur->mode != 7) {
                                    unsigned char type =
                                        (unsigned char)status.m_controllerType;
                                    if (cur) {
                                        cur->controllerType = type;
                                        ((AdventureData*)g_GameGlobal->m_advData)->selectedPad = i;
                                    }

                                    ((AdventureData*)g_GameGlobal->m_advData)->flags4924 |= 0x20;
                                    ((AdventureData*)g_GameGlobal->m_advData)->flags606 |= 0x80;

                                    unsigned char name =
                                        ((AdventureData*)g_GameGlobal->m_advData)->name;
                                    unsigned char defaultConfig[0x2d];
                                    fn_8004DA50(defaultConfig);

                                    void* config;
                                    int rumble;
                                    if (name != 0x78) {
                                        config = fn_8004DA80(g_GameGlobal, name);
                                        rumble = fn_8004D9A8(g_GameGlobal, name);
                                    } else {
                                        config = defaultConfig;
                                        unsigned char* record =
                                            (unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap();
                                        rumble =
                                            *((unsigned char*)((u32)i + (u32)record) + 0x10) != 0;
                                    }

                                    ModeData* mode = (ModeData*)g_GameGlobal->m_modeMelee;
                                    mode->rumble10f = rumble;
                                    int mask = 0;
                                    if (mode->rumbleB3)
                                        mask |= 1;
                                    if (mode->rumble10f)
                                        mask |= 2;
                                    maskMotor__11gfPadSystemFUs(g_gfPadSystem, mask ^ 0xff);
                                    fn_8004A2C8(ipPadConfig::getInstance(), 1, i, config);
                                    fn_8004A5D8(ipPadConfig::getInstance());
                                    self->state = 2;
                                }
                            }
                        }
                    }
                }
                if (self->state != 2)
                    break;
            case 2:
                if (adv->flag02 != 1) {
                    current = (AdventureData*)g_GameGlobal->m_advData;
                    if (!current->flag10) {
                        current->time = OSGetTime();
                        ((AdventureData*)g_GameGlobal->m_advData)->flags4924 |= 0x10;
                    }
                    fn_27_245178(self, 0);
                    self->state = 3;
                }
                break;

            case 3:
                if (adv->flag02 != 1) {
                    bool ready = !self->stage ? false :
                        self->stage->getPokeTrainerPointData() ? false :
                        !self->stage->getPokeTrainerPointNum() ? false :
                        fn_27_23AC10(self->stage) == 0;

                    if (ready) {
                        self->stage->renderDebugPositions()->value = 0;

                        bool doCall = true;
                        if (g_IfAdvMngr && !g_IfAdvMngr->fieldE8)
                            doCall = false;
                        if (doCall)
                            self->stage->getEnemyPac(2);

                        AdvManager* manager = g_IfAdvMngr;
                        if (manager) {
                            manager->flags &= ~0x40;
                            if (manager->field104) {
                                if (manager->flag40 == 1)
                                    fn_8010C0C4(manager->field104, fn_800DFC68());
                                else
                                    fn_8010C0DC(manager->field104, fn_800DFC68());
                            }
                        }

                        g_ftManager->getEntryId(1);
                        if (((AdventureData*)g_GameGlobal->m_advData)->mode == 7) {
                            int first = g_ftManager->getEntryId(0);
                            int second = g_ftManager->getEntryId(1);
                            int operation = 1;
                            if (first != -1)
                                operation = g_ftManager->getFighterOperationStatus(first);
                            if (second != -1)
                                fn_27_10A128(g_ftManager, second, operation);
                        }

                        float value = lbl_27_rodata_3F2C;
                        lbl_27_bss_5668->initializeFighterAttackRatio(0, value);
                        lbl_27_bss_5668->initializeFighterAttackRatio(1, value);
                        ((AdventureData*)g_GameGlobal->m_advData)->flags606 &= ~0x20;
                        self->state = 4;
                    }
                }
                break;

            case 4:
                self->state = 1;
                break;
            }
            break;
        }
        }
    }
}
