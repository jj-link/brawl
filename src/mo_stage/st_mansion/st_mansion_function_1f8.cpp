#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void initPosPokeTrainer__5StageFii(void*, int, int);
extern char lbl_47_data_C[];
}

struct Stage_base {
    char pad[0x3C];
};

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
    virtual void fn_47_184();
    virtual void fn_47_1F8();
    virtual void createObjPokeTrainer(void*, int, const char*, void*, int);
    virtual void fn_47_1534();
    virtual void fn_47_1530();
    virtual void fn_47_1524();
    virtual void fn_47_151C();
    virtual void fn_47_1514();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_47_1F0();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_47_150C();
    virtual void fn_47_1504();
    virtual void fn_47_12C4();
    virtual void fn_47_14E8();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_47_14E4();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_47_153C();
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
    virtual void fn_47_14D4();
    virtual void fn_47_14DC();
    virtual void fn_47_14CC();
    virtual void fn_47_14C4();
    virtual void fn_47_14BC();
    virtual void fn_47_14A8();
    virtual void fn_47_1498();
    virtual void fn_47_148C();
    virtual void fn_47_1480();
    virtual void fn_47_1478();
    virtual void fn_47_1470();
    virtual void fn_47_1468();
    virtual void fn_47_1464();
    virtual void isEnd();
    virtual void fn_47_13DC();
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
    virtual void fn_47_1554();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_47_145C();
    virtual void fn_47_1454();
    virtual void fn_47_144C();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_47_154C();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void fn_47_12B8();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_47_1444();
    virtual void fn_47_143C();
    virtual void fn_47_1438();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_47_1544();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_47_EA4();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_47_4EC(int);
    virtual void fn_47_5A8(int);
    virtual void fn_47_67C(int);
    virtual void fn_47_7E4(int);
    virtual void fn_47_BB4(int);
    virtual void fn_47_D98(int);

    char padToGround[0x7C];
    void* ground;
    char padToArchive[0xE0];
    void* archive;
    char padToFlag[0xC6];
    u8 flag26A;
};

struct GameGlobalSub {
    char pad0[0x8];
    u8 unk8;
    char pad9[0x7];
    u8 unk10;
};

struct GameGlobal {
    char pad0[0x8];
    GameGlobalSub* unk8;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
}

extern "C" void fn_47_1F8(Stage* self) {
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x6C);

    self->fn_47_4EC(0);
    self->fn_47_5A8(1);
    self->fn_47_67C(2);
    self->fn_47_67C(3);
    self->fn_47_7E4(4);
    self->fn_47_7E4(5);
    self->fn_47_7E4(6);
    self->fn_47_7E4(7);
    self->fn_47_7E4(8);
    self->fn_47_7E4(9);
    self->fn_47_7E4(10);
    self->fn_47_BB4(11);
    self->fn_47_BB4(12);
    self->fn_47_BB4(13);
    self->fn_47_BB4(14);
    self->fn_47_D98(15);

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
    self->initCameraParam();

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }

    self->createWind2ndOnly();
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);

    void* animData = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, animData, 0);
    initPosPokeTrainer__5StageFii(self, 1, 0);

    self->createObjPokeTrainer(self->archive, 0x65, lbl_47_data_C, self->ground, 0);

    GameGlobalSub* sub = g_GameGlobal->unk8;
    if (sub != 0 && ((((u32)sub->unk8) >> 2) & 0x3F) == 7 && sub->unk10 == 0x9E) {
        self->flag26A = 1;
    }
}
