#pragma force_active on

typedef unsigned short u16;
typedef unsigned char u8;
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
void setAreaSleep__9stTriggerFb(void*, bool);
void setWindParam__9stTriggerFP20grGimmickWindData2ndl(void*, void*, long);
int fn_800F723C(void*);
extern char lbl_71_data_C[];
extern const float lbl_71_rodata_0[];
}

struct GameGlobal { char pad[8]; u8* mode; };
extern GameGlobal* g_GameGlobal;

struct WindData {
    char pad[0x34];
    float a, b, c, d;
    char pad44[4];
    int e;
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
    virtual void fn_71_1D08();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_71_1EC();
    virtual void fn_71_284();
    virtual void createObjPokeTrainer(void*, int, const char*, int, int);
    virtual void fn_71_24E4();
    virtual void fn_71_24E0();
    virtual void fn_71_24D4();
    virtual void fn_71_24CC();
    virtual void fn_71_24C4();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_71_27C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_71_24BC();
    virtual void fn_71_24B4();
    virtual void getZoneLightSetIndex();
    virtual void fn_71_2498();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_71_2494();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_71_24EC();
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
    virtual void fn_71_2484();
    virtual void fn_71_248C();
    virtual void fn_71_247C();
    virtual void fn_71_2474();
    virtual void fn_71_246C();
    virtual void fn_71_2458();
    virtual void fn_71_2448();
    virtual void fn_71_243C();
    virtual void fn_71_2430();
    virtual void fn_71_2428();
    virtual void fn_71_2420();
    virtual void fn_71_2060();
    virtual void fn_71_241C();
    virtual void isEnd();
    virtual void fn_71_2358();
    virtual void enableDevil();
    virtual void disableDevil();
    virtual void isDevil();
    virtual void setDevilScrool();
    virtual void getLucarioFinalTechniquePosition();
    virtual void fn_71_215C();
    virtual void setAppearKind();
    virtual void fn_71_22EC();
    virtual void fn_71_2510();
    virtual void fn_71_23CC();
    virtual void fn_71_2504();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_71_2414();
    virtual void fn_71_240C();
    virtual void fn_71_2404();
    virtual void fn_71_23B8();
    virtual void fn_71_2348();
    virtual void getMadeinAiData();
    virtual void fn_71_24FC();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void fn_71_2150();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_71_23FC();
    virtual void fn_71_23F4();
    virtual void fn_71_23F0();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_71_24F4();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_71_1428();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_71_77C(int);
    virtual void fn_71_87C(int);
    virtual void fn_71_98C(int);
    virtual void fn_71_B4C(int);
    virtual void fn_71_C78(int);
    virtual void fn_71_D34(int);
    virtual void fn_71_F14();
    virtual void fn_71_FD4();
    virtual void fn_71_123C();
    virtual void fn_71_1358();
    virtual void fn_71_14CC();
    virtual void fn_71_1528();
    virtual void fn_71_1670();
    virtual void fn_71_18B0();
    virtual void fn_71_1AF4();
    virtual void fn_71_1DA0();
    virtual void fn_71_2068();

    char pad40[0x7C];
    int ground;          // 0xbc
    char padC0[0xE0];
    void* archive;       // 0x1a0
    char pad1A4[0x20];
    void* trigger;       // 0x1c4
    WindData* wind;      // 0x1c8
    char pad1CC[0xC];
    int unk1D8;          // 0x1d8
    char pad1DC[0xBA];
    u8 kind;             // 0x296
    char pad297[0x4E];
    u8 flag2E5;
    u8 flag2E6;
};

extern "C" void fn_71_284(Stage* self) {
    const float* r = lbl_71_rodata_0;
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0xA0);
    self->fn_71_2068();
    self->fn_71_87C(0);
    self->fn_71_87C(1);
    self->fn_71_77C(2);
    self->fn_71_98C(3);
    self->fn_71_98C(4);
    self->fn_71_98C(5);
    self->fn_71_98C(6);
    createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
    self->fn_71_B4C(7);
    self->fn_71_C78(8);
    self->fn_71_D34(9);
    self->fn_71_D34(10);
    self->fn_71_123C();
    self->fn_71_F14();
    self->initCameraParam();

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }
    self->createWind2ndOnly();

    if (self->trigger) {
        switch (self->kind) {
        case 3:
            setAreaSleep__9stTriggerFb(self->trigger, true);
            break;
        case 4:
            self->wind->a = r[2];
            self->wind->b = r[3];
            self->wind->c = r[4];
            self->wind->d = r[5];
            self->wind->e = 0x19;
            setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->trigger, self->wind, 0);
            setAreaSleep__9stTriggerFb(self->trigger, false);
            break;
        case 5:
            self->wind->a = r[6];
            self->wind->b = r[7];
            self->wind->c = r[8];
            self->wind->d = r[9];
            self->wind->e = 0x28;
            setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->trigger, self->wind, 0);
            setAreaSleep__9stTriggerFb(self->trigger, false);
            break;
        case 6:
            self->wind->a = r[5];
            self->wind->b = r[10];
            self->wind->c = r[11];
            self->wind->d = r[12];
            self->wind->e = 0x5A;
            setWindParam__9stTriggerFP20grGimmickWindData2ndl(self->trigger, self->wind, 0);
            setAreaSleep__9stTriggerFb(self->trigger, false);
            break;
        }
    }

    switch (self->kind) {
    case 3:
        registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE), 0);
        break;
    case 4:
        registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE), 1);
        break;
    case 5:
        registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE), 2);
        break;
    case 6:
        registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE), 3);
        break;
    }

    loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);
    initPosPokeTrainer__5StageFii(self, 1, 0);
    self->createObjPokeTrainer(self->archive, 0x65, lbl_71_data_C, self->ground, 0);
    self->unk1D8 = fn_800F723C(self->archive);

    u8* mode = g_GameGlobal->mode;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
            if ((u32)mode[0x10] == 0x2d) {
                self->flag2E5 = 1;
            }
            if ((u32)mode[0x10] == 0xad) {
                self->flag2E6 = 1;
            }
        }
    }
}
