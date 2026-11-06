#include <gf/gf_archive.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <types.h>
#pragma force_active on

class Ground;

extern "C" char lbl_67_data_C[];

struct Stage_base {
    char pad[0x3c];
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
    virtual void fn_67_100();
    virtual void fn_67_174();
    virtual void createObjPokeTrainer(gfArchive* filedata, int fileindex, const char* name, void* pokeTrainerPos, void* unk2);
    virtual void fn_67_1DEC();
    virtual void fn_67_1DE8();
    virtual void fn_67_1DDC();
    virtual void fn_67_1DD4();
    virtual void fn_67_1DCC();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_67_16C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_67_1DC4();
    virtual void fn_67_1DBC();
    virtual void getZoneLightSetIndex();
    virtual void fn_67_1DA0();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_67_1D9C();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_67_1DF4();
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
    virtual void fn_67_1D8C();
    virtual void fn_67_1D94();
    virtual void fn_67_1D84();
    virtual void fn_67_1D7C();
    virtual void fn_67_1D74();
    virtual void fn_67_1D60();
    virtual void fn_67_1D50();
    virtual void fn_67_1D44();
    virtual void fn_67_1D38();
    virtual void fn_67_1D30();
    virtual void fn_67_1D28();
    virtual void fn_67_1D20();
    virtual void fn_67_1D1C();
    virtual void isEnd();
    virtual void fn_67_1BD0();
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
    virtual void fn_67_1D14();
    virtual void fn_67_1D0C();
    virtual void fn_67_1D04();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_67_1E04();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_67_1CFC();
    virtual void fn_67_1CF4();
    virtual void fn_67_1CF0();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_67_1DFC();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_67_11D4();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_67_79C(int);
    virtual void fn_67_88C(int);
    virtual void fn_67_D2C(int);
    virtual void fn_67_E18(int);
    virtual void fn_67_FB0(int);
    virtual void fn_67_10F4(int);
    virtual void fn_67_1230();
    virtual void fn_67_14B0();
    virtual void fn_67_1B80();

    void testStageParamInit(gfArchive* archive, int fileIndex);
    void testStageDataInit(gfArchive* archive, int fileIndex, int unk2);
    void* createCollision(gfArchive* archive, int index, Ground* ground);
    void createStagePositions();
    void createStagePositions(nw4r::g3d::ResFile* resFile);
    void loadStageAttrParam(gfArchive* archive, int fileIndex);
    void registScnAnim(nw4r::g3d::ResFileData* scnData, u32 index);
    void initPosPokeTrainer(int unk1, int unk2);

    char pad40[0x5c];
    float* m_9c;
    char padA0[0x1c];
    void* m_bc;
    char padC0[0xe0];
    gfArchive* m_archive;
    char pad1A4[0x4c];
    float m_f[10];
    char pad218[0x2c];
    nw4r::g3d::ResFileData* m_resData;
    u8 m_flag;
};

extern "C" void fn_67_174(Stage* self) {
    self->testStageParamInit(self->m_archive, 10);
    self->testStageDataInit(self->m_archive, 20, 0x84);
    self->fn_67_1B80();
    self->fn_67_79C(0);
    self->fn_67_79C(1);
    self->m_resData = static_cast<nw4r::g3d::ResFileData*>(self->m_archive->getData(Data_Type_Model, 0x14, 0xFFFE));
    self->fn_67_88C(2);
    self->fn_67_88C(3);
    self->fn_67_88C(4);
    self->fn_67_88C(5);
    self->fn_67_88C(6);
    self->fn_67_88C(7);
    self->fn_67_88C(8);
    self->fn_67_88C(9);
    self->fn_67_88C(0xA);
    self->fn_67_D2C(0xB);
    self->fn_67_FB0(0xC);
    self->fn_67_FB0(0xD);
    self->fn_67_FB0(0xE);
    self->fn_67_FB0(0xF);
    self->createCollision(self->m_archive, 2, NULL);
    self->fn_67_88C(0x10);
    self->fn_67_88C(0x11);
    self->fn_67_88C(0x12);
    self->fn_67_88C(0x13);
    self->fn_67_88C(0x14);
    self->fn_67_88C(0x15);
    self->fn_67_88C(0x16);
    self->fn_67_88C(0x17);
    self->fn_67_88C(0x18);
    self->fn_67_88C(0x19);
    self->fn_67_88C(0x1A);
    self->fn_67_88C(0x1B);
    self->fn_67_88C(0x1C);
    self->fn_67_88C(0x1D);
    self->fn_67_88C(0x1E);
    self->fn_67_88C(0x1F);
    self->fn_67_88C(0x20);
    self->fn_67_88C(0x21);
    self->fn_67_10F4(0x22);
    self->fn_67_E18(0x23);
    self->fn_67_E18(0x24);
    self->fn_67_E18(0x25);
    self->fn_67_E18(0x26);
    self->fn_67_E18(0x27);
    self->fn_67_E18(0x28);
    self->fn_67_E18(0x29);
    self->fn_67_E18(0x2A);
    self->fn_67_E18(0x2B);
    self->initCameraParam();
    void* posRes = self->m_archive->getData(Data_Type_Model, 0x64, 0xFFFE);
    if (posRes != 0) {
        nw4r::g3d::ResFile posData(posRes);
        self->createStagePositions(&posData);
    } else {
        self->createStagePositions();
    }
    self->createWind2ndOnly();
    self->loadStageAttrParam(self->m_archive, 0x1E);
    self->registScnAnim(static_cast<nw4r::g3d::ResFileData*>(self->m_archive->getData(Data_Type_Scene, 0, 0xFFFE)), 0);
    self->initPosPokeTrainer(1, 0);
    self->createObjPokeTrainer(self->m_archive, 0x65, lbl_67_data_C, self->m_bc, 0);
    float* p = self->m_9c;
    if (p != NULL) {
        self->m_f[0] = *p;
        self->m_f[1] = *p;
        self->m_f[2] = *p;
        self->m_f[3] = *p;
        self->m_f[4] = *p;
        self->m_f[5] = *p;
        self->m_f[6] = *p;
        self->m_f[7] = *p;
        self->m_f[8] = *p;
        self->m_f[9] = *p;
    }
    u8* mode = (u8*)g_GameGlobal->m_modeMelee;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3f) == 7) {
            if ((u32)mode[0x10] == 3) {
                self->m_flag = 1;
            }
        }
    }
}
