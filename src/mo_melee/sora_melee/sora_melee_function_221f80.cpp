#pragma force_active on
#include <gf/gf_3d_scene.h>

struct GrCollisionList {
    u32 count;
    u8* list;
};

class IfaceA {
public:
    virtual void v0(int);
};

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
virtual void processDefault();
virtual void processBegin();
virtual void slot2();
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
virtual void slot20();
virtual void init();
virtual void slot22();
virtual void slot23();
virtual void loadGroundData();
virtual void slot25();
virtual void setupMelee();
virtual void slot27();
virtual void setVisibilityByClipping();
virtual void slot29();
virtual void receiveCollMsg();
virtual void slot31();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void getModelCount();
virtual void slot37();
virtual void slot38();
virtual void setStageData();
virtual void getStageData();
virtual void initStageData();
virtual void setMdlIndex();
virtual void getMdlIndex();
virtual void isEnableCalcCollision();
virtual void enableCalcCollision();
virtual void disableCalcCollision();
virtual void getNodeIndex();
virtual void getNodePosition();
virtual void getNodePosition_2();
virtual void getNodeMatrix();
virtual void getNodeMatrix_2();
virtual void setNodeVisibility();
virtual void setNodeVisibility_2();
virtual void setNodeVisibilityAll();
virtual void isNodeVisible();
virtual void setNodeCollision();
virtual void setNodeCollision_2();
virtual void getNodeScale();
virtual void getNodeScale_2();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void setInitializeInfo();
virtual void getInitializeInfo();
virtual void slot65();
virtual void setMotionFrame();
virtual void getMotionFrame();
virtual void setMotionLoop();
virtual void setMatAlphaMul();
virtual void setMatAlpha();
virtual void updateG3dProcCalcWorld();
virtual void slot72();
char pad40[0x10];
Ground* next50;
};
struct Ob8CBase { char pad[0x28]; };
class Ob8C : public Ob8CBase {
public:
    virtual void destroy(int);
};

extern "C" {
void fn_80060E20(void*, u32, u32, u32, u32, u32);
void __dla__FPv(void*);
void __dl__FPv(void*);
void fn_801108D0(void*, int);
void fn_27_22633C(void*, int);
void fn_27_1F290C(void*, int);
extern void* g_ecMgr;
extern GrCollisionList g_grCollisionList;
extern void* g_cmAIController;
extern void* g_aiMgr;
extern void* g_efScreen;
}

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
    char pad40[0x40];
    void* f80;
    char pad84[4];
    Ground* f88;
    Ob8C* f8C;
    void* f90;
    char pad94[4];
    u32 f98;
    u32 f9C;
    char padA0[4];
    IfaceA* fA4;
    IfaceA* fA8;
    char padAC[0x10];
    void* fBC;
};

void Stage::closeStage() {
    Ground* t;
    g_gfSceneRoot->removeResAnmScn();
    fn_80060E20(g_ecMgr, 0, 0, 1, 1, 0);

    if (fBC) {
        if (fBC) {
            __dla__FPv((u8*)fBC - 0x10);
        }
        fBC = 0;
    }

    GrCollisionList* gl = &g_grCollisionList;
    u32 n = gl->count;
    for (u32 i = 0; i < n; i++) {
        fn_801108D0(gl->list - 0x30, 1);
    }

    if (f8C) {
        if (f8C) {
            f8C->destroy(1);
        }
        f8C = 0;
    }

    int k = 0;
    for (;;) {
        t = f88;
        int j = k;
        while (j != 0 && t != 0) {
            t = t->next50;
            j--;
        }
        if (t == 0) {
            break;
        }
        t->slot72();
        ((gfTask*)t)->exit();
        k++;
    }

    void* p80 = f80;
    f88 = 0;
    if (p80) {
        __dl__FPv(p80);
        f80 = 0;
    }

    if (f90) {
        fn_27_22633C(f90, 1);
        f90 = 0;
    }

    if (fA4) {
        f98 = 0;
        if (fA4) {
            fA4->v0(1);
        }
        fA4 = 0;
    }

    if (fA8) {
        f9C = 0;
        if (fA8) {
            fA8->v0(1);
        }
        fA8 = 0;
    }

    u8* ai = (u8*)g_cmAIController;
    ai[0x94] = (u8)(ai[0x94] & ~0x20);
    fn_27_1F290C(g_aiMgr, 0);
    *(u32*)((u8*)g_efScreen + 0x1DC) = 0;
}
