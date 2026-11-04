#pragma force_active on

struct Vec { float x, y, z; };
struct Constants { float x[14]; };
extern "C" const Constants lbl_50_rodata_158;

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* d) {
        v.x = d->x[10];
        v.y = d->x[10];
        v.z = d->x[10];
        flags = 0;
    }
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
    virtual void renderDebug();
    virtual void init();
    virtual void fn_50_168();
    virtual void fn_50_1F4();
    virtual void createObjPokeTrainer();
    virtual void fn_50_1E34();
    virtual void fn_50_1E30();
    virtual void fn_50_1E24();
    virtual void fn_50_1E1C();
    virtual void fn_50_1E14();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_50_1EC();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_50_1E0C();
    virtual void fn_50_1E04();
    virtual void getZoneLightSetIndex();
    virtual void fn_50_1DE8();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_50_1DE4();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_50_1E3C();
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
    virtual void fn_50_1DD4();
    virtual void fn_50_1DDC();
    virtual void fn_50_1DCC();
    virtual void fn_50_1DC4();
    virtual void fn_50_1DBC();
    virtual void fn_50_1DA8();
    virtual void fn_50_1D98();
    virtual void fn_50_1D8C();
    virtual void fn_50_1D80();
    virtual void fn_50_1D78();
    virtual void fn_50_1D70();
    virtual void fn_50_1D68();
    virtual void fn_50_1D64();
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
    virtual void fn_50_1E54();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_50_1D5C();
    virtual void fn_50_1D54();
    virtual void fn_50_1D4C();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_50_1E4C();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady(Attack*, int, Vec*, int, int, int, int,
        float, float, float, float,
        int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int, int, int);
    char p[0xc4 - 0x40];
    int id;
    char q[0x14c - 0xc8];
    void* module;
    char r[0x194 - 0x150];
    unsigned char state;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_50_AAA8(Stage* o) {
    const Constants* d = &lbl_50_rodata_158;
    if (o->state != 1) {
        Attack a(d);
        Vec p;
        p.x = d->x[0];
        p.y = d->x[12];
        p.z = d->x[0];
        o->notifyEventInfoReady(&a, 10, &p, 0x14, 0x1c, 0, 0x5a, d->x[13], d->x[10], d->x[10], d->x[10],
            o->id, 0x3ff, 7, 0, 0xf, 5, 1, 8, 0, 0, 0, 1, 0, 0, 0, 0x3c, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
        fn_27_2636F0(o->module, 0, 0, &a);
        o->state = 1;
    }
}
