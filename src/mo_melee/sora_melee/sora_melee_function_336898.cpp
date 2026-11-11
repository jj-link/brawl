#include <so/so_value_accesser.h>
#include <so/so_external_value_accesser.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
extern const float lbl_27_rodata_76BC;
extern unsigned char lbl_27_data_248[];
extern unsigned char __RTTI__6gfTask[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
unsigned int fn_27_8D810(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_338624(void*, int, int, float*, float);
}

struct Selector { void* article; };
struct ModuleData {
    char pad0[4];
    soModelModule* value;
    char pad8[0x10];
    soModelModule* module18;
    char pad1c[0x48];
    soModelModule* module64;
};
struct AccesserLayout {
    char pad0[8];
    void* object;
    char padc[0xcc];
    ModuleData* modules;
};
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
    virtual void helperStarWarp();
    virtual void initializeFighterAttackRatio();
    virtual void startFighterEvent();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void slot123();
    virtual void slot124();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3();
    virtual unsigned int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
};

inline char* findOwner(char* object, Selector& selector)
{
    if (fn_27_8D810(&selector, object + 0x9d30) == 1)
        return object + 0x9ca8;
    if (fn_27_8D810(&selector, object + 0x7de4) == 1)
        return object + 0x7d5c;
    if (fn_27_8D810(&selector, object + 0x5e98) == 1)
        return object + 0x5e10;
    if (fn_27_8D810(&selector, object + 0x3f4c) == 1)
        return object + 0x3ec4;
    if (fn_27_8D810(&selector, object + 0x2000) == 1)
        return object + 0x1f78;
    if (fn_27_8D810(&selector, object + 0xb4) == 1)
        return object + 0x2c;
    return 0;
}
extern "C" void* fn_27_336898(char* object, unsigned int kind, soModuleAccesser* accesser)
{
    switch (kind) {
    case 0: {
        soModelModule* valueObject;
        Selector selector;
        fn_27_8D7C4(&selector);
        char* owner = findOwner(object, selector);
        if (!owner) {
            owner = static_cast<char*>(selector.article);
            if (owner)
                owner -= 0x88;
            if (!owner) {
                fn_27_8D7D0(&selector, -1);
                return lbl_27_bss_1CC;
            }
            reinterpret_cast<Object_vptr_3c*>(owner)->slot124();
        }
        valueObject = reinterpret_cast<AccesserLayout*>(accesser)->modules->value;
        int index = soValueAccesser::getConstantInt(accesser, 0x5dc0, 0);
        Vec3f position = valueObject->getNodeGlobalPosition(index, false);
        position.m_x += soValueAccesser::getConstantFloat(accesser, 0xfa0, 0);
        position.m_y += soValueAccesser::getConstantFloat(accesser, 0xfa1, 0);
        position.m_z = lbl_27_rodata_76BC;
        Object_vptr_0* work = reinterpret_cast<Object_vptr_0*>(
            reinterpret_cast<AccesserLayout*>(accesser)->modules->module64);
        float lr = work->slot12(0x11000001);
        work = reinterpret_cast<Object_vptr_0*>(
            reinterpret_cast<AccesserLayout*>(accesser)->modules->module64);
        unsigned int taskId = work->slot4(0x10000000);
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
            static_cast<gfTask::Category>(10), taskId);
        StageObject* external = static_cast<StageObject*>(
            __dynamic_cast(task, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 0));
        if (external)
            lr = soExternalValueAccesser::getLr(external);
        int value = *reinterpret_cast<int*>(
            static_cast<char*>(
                reinterpret_cast<AccesserLayout*>(accesser)->object) + 0x28);
        Object_vptr_0* first = reinterpret_cast<Object_vptr_0*>(
            reinterpret_cast<AccesserLayout*>(accesser)->modules->module18);
        Object_vptr_0* second = static_cast<Object_vptr_0*>(first->slot2());
        int result = reinterpret_cast<int>(second->slot2());
        fn_27_338624(owner, value, result, &position.m_x, lr);
        fn_27_8D7D0(&selector, -1);
        return lbl_27_bss_1CC;
    }
    case 1: return lbl_27_bss_1CC;
    case 2: return lbl_27_bss_1CC;
    case 3: return lbl_27_bss_1CC;
    case 4: return lbl_27_bss_1CC;
    case 5: return lbl_27_bss_1CC;
    case 6: return lbl_27_bss_1CC;
    case 7: return lbl_27_bss_1CC;
    case 8: return lbl_27_bss_1CC;
    case 9: return lbl_27_bss_1CC;
    case 10: return lbl_27_bss_1CC;
    case 11: return lbl_27_bss_1CC;
    case 12: return lbl_27_bss_1CC;
    case 13: return lbl_27_bss_1CC;
    case 14: return lbl_27_bss_1CC;
    case 15: return lbl_27_bss_1CC;
    case 16: return lbl_27_bss_1CC;
    default: return lbl_27_bss_1CC;
    }
}
