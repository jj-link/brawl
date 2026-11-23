#include <ft/ft_manager.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct Position {
    float x, y, z;
};

struct FighterData {
    unsigned char kind;
    unsigned char state;
    unsigned char player;
    char pad03[5];
    signed char point;
    signed char direction;
    char pad0a[0x18];
    unsigned short damage;
};

struct Object_vptr_c_base {
    char pad[0xc];
};

class Object_vptr_c : public Object_vptr_c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(float);
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
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage(int);
    virtual void getItemPac();
    virtual void slot31();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual FighterData* renderDebugPositions();
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
    virtual void slot54(Position*, int);
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
    virtual void startFighterEvent(int);
};

struct Self : Object_vptr_3c {
    int field40;
    char pad44[4];
    int field48;
    int entryId;
    char pad50[0xd];
    unsigned char flag : 1;
};

struct Entry {
    int value;
    int unused;
    float x;
    float y;
};

struct GameRules {
    char pad[0x4924];
    unsigned char : 1;
    unsigned char flag : 1;
};

struct GameGlobal {
    char pad[0x30];
    GameRules* rules;
};

struct IfAdvManager {
    char pad00[0x55];
    unsigned char field55;
    char pad56[0x92];
    void* players[1];
};

struct IfManager {
    char pad00[0x4c];
    void* players[7];
    unsigned char playerMap[1];
};

extern "C" {
extern const float lbl_27_rodata_3978[];
extern Object_vptr_3c* lbl_27_bss_5668;
extern GameGlobal* g_GameGlobal;
extern IfAdvManager* g_IfAdvMngr;
extern IfManager* g_IfMngr;

int fn_27_23AC10(void*);
void fn_27_23AC24(void*);
void fn_27_23BC0C(void*);
float fn_27_23E890(int, int);
int fn_27_10AAC4(ftManager*, int);
void fn_27_109920(ftManager*, int);
void fn_27_109D50(ftManager*, int, int);
void fn_27_111B38(Object_vptr_c*, float);
void fn_27_111B5C(Object_vptr_c*, Position*);
void fn_27_111F38(Object_vptr_c*, int);
void fn_27_112640(Object_vptr_c*, int, float, float);
void fn_27_112A24(Object_vptr_c*);
void fn_27_112E0C(Object_vptr_c*, int);
void* fn_80158BE0();
void fn_8015A3A0(void*, int, int*, Entry**);
void fn_800E14A4(void*, unsigned short, int);
void fn_800E3684(void*, int);
void fn_80107A70(IfAdvManager*, int, int);
}

extern "C" void fn_27_23DAD8(Self* self, int arg1) {
    float forward = 1.0f;
    float zero = 0.0f;
    float reverse = -1.0f;
    float slowdown = 0.6f;
    float half = 0.5f;
    float scale = 0.88f;
    double unsignedBias = 4503599627370496.0;
    FighterData* data = self->renderDebugPositions();
    if (data && data->state != 3 && self->getPokeTrainerPointNum()) {
        Position pos;
        pos.x = 0.0;
        pos.y = 0.0f;
        pos.z = 0.0f;

        if (lbl_27_bss_5668)
            lbl_27_bss_5668->slot54(&pos, data->point);

        float direction = 1.0f;
        switch (data->direction) {
        case 0:
            direction = fn_27_23E890(self->field40, self->field48);
            break;
        case 1:
            direction = 1.0f;
            break;
        case -1:
            direction = -1.0f;
            break;
        }

        int kind;
        if (fn_27_23AC10(self)) {
            Object_vptr_c* owner =
                (Object_vptr_c*)g_ftManager->getOwner(self->entryId);
            if (self->flag) {
                kind = fn_27_10AAC4(g_ftManager, self->entryId);
                Entry* entries;
                int count;
                fn_8015A3A0(fn_80158BE0(), kind, &count, &entries);
                fn_27_112A24(owner);
                int i = 0;
                int offset = 0;
                for (; i < count; offset += 0x10, ++i) {
                    Entry* entry = (Entry*)((char*)entries + offset);
                    fn_27_112640(owner, entry->value, entry->x, entry->y);
                }
            }

            owner->slot4((float)data->damage);
            fn_27_111B5C(owner, &pos);
            fn_27_111B38(owner, direction);
            fn_27_111F38(owner, 1);
            if ((int)data->kind == 0x10)
                fn_27_112E0C(owner, 0);

            if (!g_GameGlobal->rules->flag)
                fn_27_109D50(g_ftManager, self->entryId, 4);
            else
                fn_27_109D50(g_ftManager, self->entryId, 3);

            if (lbl_27_bss_5668)
                lbl_27_bss_5668->startFighterEvent(self->field48);

            if (g_IfAdvMngr) {
                fn_800E14A4(g_IfAdvMngr->players[data->player],
                            data->damage, 0);
                fn_800E3684(g_IfAdvMngr->players[data->player], 3);
                g_IfAdvMngr->field55 = self->field48;
                fn_80107A70(g_IfAdvMngr, 1, 1);
            }

            if (g_IfMngr && g_GameGlobal->rules->flag) {
                fn_800E14A4(
                    g_IfMngr->players[g_IfMngr->playerMap[data->player]],
                    data->damage, 0);
                fn_800E3684(
                    g_IfMngr->players[g_IfMngr->playerMap[data->player]],
                    3);
            }
        } else {
            if (self->entryId == -1)
                fn_27_23BC0C(self);

            int offset;
            int i;
            Object_vptr_c* owner =
                (Object_vptr_c*)g_ftManager->getOwner(self->entryId);
            if (self->flag) {
                kind = fn_27_10AAC4(g_ftManager, self->entryId);
                Entry* entries;
                int count;
                fn_8015A3A0(fn_80158BE0(), kind, &count, &entries);
                fn_27_112A24(owner);
                i = 0;
                offset = 0;
                for (; i < count; offset += 0x10, ++i) {
                    Entry* entry = (Entry*)((char*)entries + offset);
                    fn_27_112640(owner, entry->value, entry->x, entry->y);
                }
            }

            owner->slot4((float)data->damage);
            fn_27_111B5C(owner, &pos);
            fn_27_111B38(owner, direction);
            fn_27_111F38(owner, 1);
            fn_27_109920(g_ftManager, self->entryId);
            fn_27_109D50(g_ftManager, self->entryId, arg1);

            if (lbl_27_bss_5668)
                lbl_27_bss_5668->startFighterEvent(self->field48);

            self->getPokeTrainerDrawLayer();
            self->isAdventureStage(1);

            if (g_IfAdvMngr) {
                g_IfAdvMngr->field55 = self->field48;
                fn_80107A70(g_IfAdvMngr, 1, 1);
            }
            fn_27_23AC24(self);
        }
    }
}
