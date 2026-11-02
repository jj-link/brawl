#pragma force_active on

typedef unsigned short u16;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void initPosPokeTrainer__5StageFii(void*, int, int);
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
    virtual void fn_46_3FEC();
    virtual void init();
    virtual void fn_46_280();
    virtual void fn_46_354_slot();
    virtual void createObjPokeTrainer();
    virtual void fn_46_4384();
    virtual void fn_46_4380();
    virtual void fn_46_4374();
    virtual void fn_46_436C();
    virtual void fn_46_4364();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_46_34C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_46_435C();
    virtual void fn_46_4354();
    virtual void getZoneLightSetIndex();
    virtual void fn_46_4338();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_46_4334();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_46_438C();
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
    virtual void fn_46_4324();
    virtual void fn_46_432C();
    virtual void fn_46_431C();
    virtual void fn_46_4314();
    virtual void fn_46_430C();
    virtual void fn_46_42F8();
    virtual void fn_46_42E8();
    virtual void fn_46_42DC();
    virtual void fn_46_42D0();
    virtual void fn_46_42C8();
    virtual void fn_46_42C0();
    virtual void fn_46_42B8();
    virtual void fn_46_42B4();
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
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_46_42AC();
    virtual void fn_46_42A4();
    virtual void fn_46_429C();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void isBamperVector();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_46_4294();
    virtual void fn_46_428C();
    virtual void fn_46_4288();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_46_4394();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_46_1024();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_46_688();
    virtual void fn_46_6EC();
    virtual void fn_46_8F0(int);
    virtual void fn_46_9BC(int);
    virtual void fn_46_C40();
    virtual void fn_46_CF8(int);
    virtual void fn_46_E28(int);
    virtual void fn_46_F58();

    char padToGround[0x7C];
    void* ground;
    char padToArchive[0xE0];
    void* archive;
};

extern "C" void fn_46_354(Stage* self) {
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x24);
    initPosPokeTrainer__5StageFii(self, 4, 1);

    self->fn_46_688();
    self->fn_46_6EC();
    self->fn_46_8F0(1);
    self->fn_46_9BC(2);
    self->fn_46_9BC(3);
    self->fn_46_9BC(4);
    self->fn_46_9BC(5);
    self->fn_46_9BC(6);
    self->fn_46_9BC(7);
    self->fn_46_9BC(8);
    self->fn_46_9BC(9);
    self->fn_46_9BC(0xA);
    self->fn_46_9BC(0xB);
    self->fn_46_9BC(0xC);

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 3, 0);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 4, 0);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 5, 0);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 6, 0);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 7, 0);

    self->fn_46_C40();
    self->fn_46_CF8(0xE);
    self->fn_46_CF8(0xF);
    self->fn_46_E28(0x10);
    self->fn_46_E28(0x11);
    self->fn_46_E28(0x12);
    self->fn_46_E28(0x13);
    self->fn_46_F58();
    self->initCameraParam();

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(
        self->archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }

    self->createWind2ndOnly();
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);
}
