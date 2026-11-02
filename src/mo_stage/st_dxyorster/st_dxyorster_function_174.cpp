#pragma force_active on

typedef unsigned short u16;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void initPosPokeTrainer__5StageFii(void*, int, int);
extern char lbl_76_data_C[];
extern char lbl_76_data_1C[];
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
    virtual void fn_76_100();
    virtual void fn_76_174();
    virtual void createObjPokeTrainer(void*, int, const char*, void*, void*);
    virtual void fn_76_974();
    virtual void fn_76_970();
    virtual void fn_76_964();
    virtual void fn_76_95C();
    virtual void fn_76_954();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_76_16C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_76_94C();
    virtual void fn_76_944();
    virtual void getZoneLightSetIndex();
    virtual void fn_76_928();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_76_924();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_76_97C();
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
    virtual void fn_76_914();
    virtual void fn_76_91C();
    virtual void fn_76_90C();
    virtual void fn_76_904();
    virtual void fn_76_8FC();
    virtual void fn_76_8E8();
    virtual void fn_76_8D8();
    virtual void fn_76_8CC();
    virtual void fn_76_8C0();
    virtual void fn_76_8B8();
    virtual void fn_76_8B0();
    virtual void fn_76_8A8();
    virtual void fn_76_8A4();
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
    virtual void fn_76_89C();
    virtual void fn_76_894();
    virtual void fn_76_88C();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_76_98C();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_76_884();
    virtual void fn_76_87C();
    virtual void fn_76_878();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_76_984();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_76_874();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_76_400(int);
    virtual void fn_76_514(int);
    virtual void fn_76_6F0(int);
    virtual void fn_76_618();

    char pad40[0x7C];
    void* ground;
    char padC0[0xE0];
    void* archive;
};

extern "C" void fn_76_174(Stage* self) {
    self->fn_76_400(0);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
    self->fn_76_514(1);
    self->fn_76_514(2);
    self->fn_76_618();
    self->fn_76_6F0(0);
    self->fn_76_6F0(1);
    self->fn_76_6F0(2);
    self->fn_76_6F0(3);
    self->fn_76_6F0(4);
    self->fn_76_6F0(5);
    self->fn_76_6F0(6);
    self->fn_76_6F0(7);
    self->fn_76_6F0(8);
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
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
    initPosPokeTrainer__5StageFii(self, 2, 0);

    self->createObjPokeTrainer(self->archive, 0x65, lbl_76_data_C, self->ground, 0);
    self->createObjPokeTrainer(self->archive, 0x66, lbl_76_data_1C, (char*)self->ground + 0x18, 0);
}
