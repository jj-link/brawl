#pragma force_active on

typedef unsigned short u16;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void*, int, int, int*, u16);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void initPosPokeTrainer__5StageFii(void*, int, int);
extern char lbl_88_data_C[];
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
    virtual void fn_88_2D10();
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
    virtual void fn_88_320();
    virtual void fn_88_3E8();
    virtual void createObjPokeTrainer(void*, int, const char*, void*, void*);
    virtual void fn_88_41E4();
    virtual void fn_88_41E0();
    virtual void fn_88_41D4();
    virtual void fn_88_41CC();
    virtual void fn_88_41C4();
    virtual void fn_88_3CB8();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_88_3E0();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_88_41BC();
    virtual void fn_88_41B4();
    virtual void getZoneLightSetIndex();
    virtual void fn_88_4198();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_88_4194();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_88_41EC();
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
    virtual void fn_88_4184();
    virtual void fn_88_418C();
    virtual void fn_88_417C();
    virtual void fn_88_4174();
    virtual void fn_88_416C();
    virtual void fn_88_4158();
    virtual void fn_88_4148();
    virtual void fn_88_413C();
    virtual void fn_88_4130();
    virtual void fn_88_4128();
    virtual void fn_88_4120();
    virtual void fn_88_2590();
    virtual void fn_88_411C();
    virtual void fn_88_3B5C();
    virtual void fn_88_3B4C();
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
    virtual void fn_88_4114();
    virtual void fn_88_410C();
    virtual void fn_88_4104();
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
    virtual void fn_88_40FC();
    virtual void fn_88_40F4();
    virtual void fn_88_40F0();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_88_41F4();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_88_18C0();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_88_9D0(int);
    virtual void fn_88_B5C(int);
    virtual void fn_88_DE0(int);
    virtual void fn_88_106C(int);
    virtual void fn_88_14D0(int);
    virtual void fn_88_15B4();
    virtual void fn_88_1630();
    virtual void fn_88_1800();

    char pad40[0x7C];
    void* unkBC;
    char padC0[0xE0];
    void* archive;
};

extern "C" void fn_88_3E8(Stage* self) {
    int size;
    void* data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2711, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType((char*)self + 0x5F0, data, size, 0x11);
    }
    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2712, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType((char*)self + 0x670, data, size, 0x11);
    }
    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2713, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType((char*)self + 0x6F0, data, size, 0x11);
    }
    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2714, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType((char*)self + 0x770, data, size, 0x11);
    }

    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x8);

    self->initCameraParam();
    self->fn_88_9D0(0);
    self->fn_88_B5C(1);
    self->fn_88_B5C(2);
    self->fn_88_B5C(3);
    self->fn_88_B5C(4);
    self->fn_88_B5C(5);
    self->fn_88_B5C(6);
    self->fn_88_DE0(7);
    self->fn_88_DE0(8);
    self->fn_88_DE0(9);
    self->fn_88_DE0(0xA);
    self->fn_88_DE0(0xB);
    self->fn_88_DE0(0xC);
    self->fn_88_106C(0xD);
    self->fn_88_106C(0xE);
    self->fn_88_106C(0xF);
    self->fn_88_106C(0x10);
    self->fn_88_106C(0x11);
    self->fn_88_106C(0x12);
    self->fn_88_106C(0x13);
    self->fn_88_106C(0x14);
    self->fn_88_106C(0x15);
    self->fn_88_106C(0x16);
    self->fn_88_106C(0x17);
    self->fn_88_106C(0x18);
    self->fn_88_106C(0x19);
    self->fn_88_106C(0x1A);
    self->fn_88_106C(0x1B);
    self->fn_88_106C(0x1C);
    self->fn_88_106C(0x1D);
    self->fn_88_106C(0x1E);
    self->fn_88_106C(0x1F);
    self->fn_88_106C(0x20);
    self->fn_88_106C(0x21);
    self->fn_88_106C(0x22);
    self->fn_88_106C(0x23);
    self->fn_88_106C(0x24);
    self->fn_88_14D0(0x25);
    self->fn_88_15B4();

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
    self->fn_88_1800();

    void* posData = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, (u16)0xFFFE);
    if (posData != 0) {
        void* p = posData;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &p);
    } else {
        createStagePositions__5StageFv(self);
    }

    self->createWind2ndOnly();
    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);

    void* animData = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, animData, 0);
    initPosPokeTrainer__5StageFii(self, 1, 0);

    self->createObjPokeTrainer(self->archive, 0x65, lbl_88_data_C, self->unkBC, 0);
}
