#pragma force_active on

typedef unsigned char u8;

struct Vec {
    float x, y, z;
};

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;
};

struct Rodata {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
};

extern "C" const Rodata lbl_52_rodata_238;

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
    virtual void fn_52_218();
    virtual void fn_52_2B0();
    virtual void createObjPokeTrainer();
    virtual void fn_52_34A0();
    virtual void fn_52_349C();
    virtual void fn_52_3490();
    virtual void fn_52_3488();
    virtual void fn_52_3480();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_52_2A8();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_52_3478();
    virtual void fn_52_3470();
    virtual void getZoneLightSetIndex();
    virtual void fn_52_3454();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_52_3450();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_52_34A8();
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
    virtual void fn_52_3440();
    virtual void fn_52_3448();
    virtual void fn_52_3438();
    virtual void fn_52_3430();
    virtual void fn_52_3428();
    virtual void fn_52_3414();
    virtual void fn_52_3404();
    virtual void fn_52_33F8();
    virtual void fn_52_33EC();
    virtual void fn_52_33E4();
    virtual void fn_52_33DC();
    virtual void fn_52_2810();
    virtual void fn_52_33D8();
    virtual void isEnd();
    virtual void fn_52_3310();
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
    virtual void fn_52_33D0();
    virtual void fn_52_33C8();
    virtual void fn_52_33C0();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void isBamperVector();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady(Attack*, int, Vec*, int, int, int, int,
        float, float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int);

    char q[0x14c - 0x40];
    void* module;
    char s[0x1a2 - 0x150];
    u8 state;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_52_E564(u8* self) {
    const Rodata* d = &lbl_52_rodata_238;
    if (self[0x1a2] != 1) {
        Attack a;
        Vec p;
        a.v.x = d->f10;
        a.v.y = d->f10;
        a.v.z = d->f10;
        a.flags = 0;
        p.x = d->f0;
        p.y = d->f0;
        p.z = d->f0;
        ((Stage*)self)->notifyEventInfoReady(&a, 0x14, &p, 0x169, 0x64, 0, 0x46,
            d->f3c, d->f10, d->f10, d->f10,
            *(int*)(self + 0xc4), 0x3ff, 7, 0, 0xf, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0x3c,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
        fn_27_2636F0(*(void**)(self + 0x14c), 0, 0, &a);
        self[0x1a2] = 1;
    }
}