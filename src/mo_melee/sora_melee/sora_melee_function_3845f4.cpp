#include <types.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4(s32);
    virtual void slot5(void*, s32, void*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual StageObject* slot11(s32);
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual s32 slot15();
};

struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual Object_vptr_0* fn_27_7B2EC();
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
    virtual void* getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void slot123();
    virtual void slot124();
};

extern "C" {
extern char lbl_27_bss_1CC[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
void fn_27_8D7C4(void*);
u32 fn_27_8D810(void*, void*);
void fn_27_8D7D0(void*, s32);
u32 fn_27_383B38(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
s32 fn_27_14DB04(void*);
void fn_27_3944BC(void*, s32, s32, s32, s32, s32, s32, void*, f32);

void* fn_27_3845F4(char* self, u32 kind, char* acc) {
    Object_vptr_0* m64;
    s32 r30;
    s32 r29;
    s32 team;
    s32 r28;
    s32 r27;
    s32 r26i;
    char* r26;
    switch (kind) {
    case 0: {
        void* spC;
        fn_27_8D7C4(&spC);
        if (fn_27_8D810(&spC, self + 0x211c) == 1) {
            r26 = self + 0x2094;
        } else {
            r26 = 0;
        }
        if (r26 == 0) {
            r26 = (char*)spC;
            if (r26 != 0) {
                r26 = r26 - 0x88;
            }
            if (r26 == 0) {
                fn_27_8D7D0(&spC, -1);
                return lbl_27_bss_1CC;
            }
            ((Object_vptr_3c*)r26)->slot124();
        }
        if (fn_27_383B38(r26, acc) == 1) {
            fn_27_8D7D0(&spC, -1);
            return r26 + 0x88;
        }
        fn_27_8D7D0(&spC, -1);
        return lbl_27_bss_1CC;
    }
    case 1: {
        void* sp8;
        char* article;
        fn_27_8D7C4(&sp8);
        if (fn_27_8D810(&sp8, self + 0xa0) == 1) {
            article = self + 0x18;
        } else {
            article = 0;
        }
        if (article == 0) {
            article = (char*)sp8;
            if (article != 0) {
                article = article - 0x88;
            }
            if (article == 0) {
                fn_27_8D7D0(&sp8, -1);
                return lbl_27_bss_1CC;
            }
            ((Object_vptr_3c*)article)->slot124();
        }
        {
            char* mods = *(char**)(acc + 0xd8);
            Object_vptr_0* p54 = *(Object_vptr_0**)(mods + 0x54);
            r28 = (s32)p54->slot11(6);
        }
        {
            char* mods = *(char**)(acc + 0xd8);
            r30 = *(s32*)mods;
            m64 = *(Object_vptr_0**)(mods + 0x64);
            r27 = *(s32*)((char*)r28 + 0x28);
            char* stage = *(char**)(acc + 8);
            r26i = *(s32*)(stage + 0x28);
            f32 f31 = soExternalValueAccesser::getLr((StageObject*)r28);
            Vec3f sp10 = soExternalValueAccesser::getPos((StageObject*)r28);
            team = soExternalValueAccesser::getTeamNo((StageObject*)r28);
            r29 = ((Class_90D8*)r30)->fn_27_7B2EC()->slot15();
            r30 = fn_27_14DB04(__dynamic_cast(((Class_90D8*)r30)->fn_27_7B2EC(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1));
            s32 r6 = m64->slot4(0x10000049);
            fn_27_3944BC(article, r26i, r27, r6, r30, r29, team, &sp10, f31);
            void* r4v = ((Object_vptr_3c*)article)->getZonePos();
            char* mods3 = *(char**)(acc + 0xd8);
            Object_vptr_0* r3b = *(Object_vptr_0**)(mods3 + 0x64);
            r3b->slot5(r4v, 0x10000043, mods3);
        }
        fn_27_8D7D0(&sp8, -1);
        return article + 0x88;
    }
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
}