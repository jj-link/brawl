#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct State {
    char pad0[0x40];
    u8 mode;
    char pad41[0x8B];
    float current;
    float limit;
    bool enabled;
};
struct Flags { u8 a : 1; u8 b : 1; u8 rest : 6; };
struct Game {
    char pad0[0x604];
    u8 mode;
    u8 reset;
    char pad606[0x16];
    u32 count;
    char pad620[0x4304];
    Flags flags;
};
struct Global { char pad0[0x30]; Game* game; };
struct Adv {
    char pad0[0x48];
    u8 enabled;
    char pad49[3];
    u32 count;
};
struct Interface { char pad0[0x44]; void* timer; };
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
};
extern "C" {
extern Global* g_GameGlobal;
extern Adv* g_IfAdvMngr;
extern Interface* g_IfMngr;
extern Stage* lbl_27_bss_5668;
extern float lbl_27_rodata_40C8;
void fn_800DDCF8(void*, u32);
void* fn_80158BE0();
int fn_801590F0(void*, int);
void fn_801590A0(void*, int, int);
}
union AdvFlag {
    u8 byte;
    struct { u8 enabled : 1; u8 rest : 7; } bits;
};
extern "C" void fn_27_25203C(State* self) {
    Game* game = g_GameGlobal->game;
    game->reset = 0;
    if (game->flags.a) {
        self->current = lbl_27_rodata_40C8;
        self->limit = (float)(unsigned int)game->count;
        self->enabled = 1;
    } else if (game->flags.b) {
        self->current = (float)game->count;
        self->limit = (float)game->count;
        self->enabled = 1;
    } else if (game->count != 0) {
        self->current = (float)game->count;
        self->enabled = 1;
    }
    if (g_IfAdvMngr) {
        g_IfAdvMngr->count = (u32)self->current;
        Adv* adv = g_IfAdvMngr;
        AdvFlag flag;
        flag.byte = adv->enabled;
        flag.bits.enabled = self->enabled;
        adv->enabled = flag.byte;
    }
    if (g_IfMngr) {
        fn_800DDCF8(g_IfMngr->timer, (u32)self->limit);
    }
    if (lbl_27_bss_5668) {
        lbl_27_bss_5668->notifyTimmingGameStart();
    }
    if (game->flags.b) {
        self->mode = 3;
    } else if (game->flags.a) {
        if (game->mode == 2) self->mode = 1;
        else self->mode = 3;
    } else {
        if (fn_801590F0(fn_80158BE0(), 1002) == 0) self->mode = 1;
        else self->mode = 3;
    }
    fn_801590A0(fn_80158BE0(), 1002, 0);
}
