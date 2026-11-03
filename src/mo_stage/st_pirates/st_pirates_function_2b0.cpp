#pragma force_active on

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void initPosPokeTrainer__5StageFii(void*, int, int);
char lbl_52_data_C[];
}

struct Stage_base { char pad[0x3C]; };

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
    virtual void createObjPokeTrainer(void*, int, const char*, void*, void*);
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
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_52_33B8();
    virtual void fn_52_33B0();
    virtual void fn_52_33AC();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_52_34B0();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_52_1CA4();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_52_72C(int);
    virtual void fn_52_86C(int);
    virtual void fn_52_A2C(int);
    virtual void fn_52_B78(int);
    virtual void fn_52_C68(int);
    virtual void fn_52_DC4(int);
    virtual void fn_52_EB0(int);
    virtual void fn_52_FE8(int);
    virtual void fn_52_1120(int);
    virtual void fn_52_1230(int);
    virtual void fn_52_1320(int);
    virtual void fn_52_15B8(int);
    virtual void fn_52_1710(int);
    virtual void fn_52_1898(int);
    virtual void fn_52_1964(int);
    virtual void fn_52_1A6C(int);
    virtual void fn_52_1BE4();

    char padToGround[0x7C];
    void* ground;
    char padToArchive[0xE0];
    void* archive;
    char padToFlag55C[0x3B8];
    u8 flag55C;
    char padToFlag608[0xAB];
    u8 flag608;
};

struct ModeMelee { char pad[0x10]; };
struct GameGlobal { char pad[0x8]; ModeMelee* m_modeMelee; };
extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_52_2B0(Stage* self) {
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0x98);

    self->fn_52_72C(0);
    self->fn_52_1120(1);
    self->fn_52_86C(3);
    self->fn_52_86C(2);
    self->fn_52_86C(4);
    self->fn_52_EB0(5);
    self->fn_52_EB0(6);
    self->fn_52_1230(7);
    self->fn_52_1320(8);
    self->fn_52_1320(9);
    self->fn_52_1320(0xA);
    self->fn_52_1320(0xB);
    self->fn_52_1320(0xC);
    self->fn_52_1320(0xD);
    self->fn_52_1320(0xE);
    self->fn_52_1320(0xF);
    self->fn_52_15B8(0x10);
    self->fn_52_FE8(0x11);
    self->fn_52_C68(0x12);
    self->fn_52_DC4(0x13);
    self->fn_52_1964(0x14);
    self->fn_52_A2C(0x15);
    self->fn_52_B78(0x16);
    self->fn_52_1710(0x17);
    self->fn_52_1710(0x18);
    self->fn_52_1710(0x19);
    self->fn_52_1710(0x1A);
    self->fn_52_1898(0x1B);
    self->fn_52_1964(0x1C);
    self->fn_52_1A6C(0x1D);
    self->fn_52_1A6C(0x1E);
    self->fn_52_1A6C(0x1F);
    self->fn_52_1BE4();
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

    self->flag55C = 0;
    initPosPokeTrainer__5StageFii(self, 1, 0);

    self->createObjPokeTrainer(self->archive, 0x65, lbl_52_data_C, self->ground, 0);

    ModeMelee* mode = g_GameGlobal->m_modeMelee;
    if (mode != 0) {
        u8* m = (u8*)mode;
        if ((((u32)m[8] >> 2) & 0x3F) == 7) {
            if (m[0x10] == 0x27) {
                self->flag608 = 1;
            }
        }
    }
}