#include <gf/gf_archive.h>
#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

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
}

struct CameraController_base {
    char pad[0x44];
};

class CameraController : public CameraController_base {
public:
    u8 m_44;
};

extern "C" CameraController* getInstance__16CameraControllerFv();

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
    virtual void fn_81_570();
    virtual void fn_81_620();
    virtual void createObjPokeTrainer();
    virtual void fn_81_4050();
    virtual void fn_81_404C();
    virtual void fn_81_4040();
    virtual void fn_81_4038();
    virtual void fn_81_4030();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_81_618();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_81_4028();
    virtual void fn_81_4020();
    virtual void getZoneLightSetIndex();
    virtual void fn_81_4004();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_81_4000();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_81_4058();
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
    virtual void fn_81_3FF0();
    virtual void fn_81_3FF8();
    virtual void fn_81_3FE8();
    virtual void fn_81_3FE0();
    virtual void fn_81_3FD8();
    virtual void fn_81_3FC4();
    virtual void fn_81_3FB4();
    virtual void fn_81_3FA8();
    virtual void fn_81_3F9C();
    virtual void fn_81_3F94();
    virtual void fn_81_3F8C();
    virtual void fn_81_3F84();
    virtual void fn_81_3F80();
    virtual void isEnd();
    virtual void fn_81_3F40();
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
    virtual void fn_81_3F78();
    virtual void fn_81_3F70();
    virtual void fn_81_3F68();
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
    virtual void fn_81_3F60();
    virtual void fn_81_3F58();
    virtual void fn_81_3F54();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_81_4060();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_81_1498();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_81_984(int);
    virtual void fn_81_ABC(int);
    virtual void fn_81_C04(int);
    virtual void fn_81_D20(int);
    virtual void fn_81_DFC(int);
    virtual void fn_81_ED8(int);
    virtual void fn_81_11BC();

    char padToArchive[0x1A0 - 0x40];
    gfArchive* m_archive;
    char padToFlag[0xC38 - 0x1A4];
    u8 m_flag;
};

extern "C" void fn_81_620(Stage* self) {
    CameraController* cc = getInstance__16CameraControllerFv();
    cc->m_44 |= 4;

    testStageParamInit__5StageFP9gfArchivei(self, self->m_archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->m_archive, 0x14, 0x144);
    initPosPokeTrainer__5StageFii(self, 4, 1);

    self->fn_81_984(0);
    self->fn_81_984(1);
    self->fn_81_ED8(2);
    self->fn_81_ED8(3);
    self->fn_81_ED8(4);
    self->fn_81_ED8(5);
    self->fn_81_ED8(6);
    self->fn_81_ED8(7);
    self->fn_81_ED8(8);
    self->fn_81_ED8(9);
    self->fn_81_ED8(0xA);
    self->fn_81_ED8(0xB);
    self->fn_81_ED8(0xC);
    self->fn_81_ED8(0xD);

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->m_archive, 2, 0);

    self->fn_81_ABC(0xE);
    self->fn_81_ABC(0xF);
    self->fn_81_ABC(0x10);
    self->fn_81_C04(0x11);
    self->fn_81_D20(0x12);
    self->fn_81_DFC(0x13);

    createCollision__5StageFP9gfArchiveiP6Ground(self, self->m_archive, 3, 0);

    self->fn_81_11BC();
    self->initCameraParam();

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(self->m_archive, 2, 0x64, (u16)0xFFFE);
    if (data) {
        void* posData = data;
        createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
    } else {
        createStagePositions__5StageFv(self);
    }

    self->createWind2ndOnly();
    loadStageAttrParam__5StageFP9gfArchivei(self, self->m_archive, 0x46);

    void* animData = getData__9gfArchiveF11ARCNodeTypeiUs(self->m_archive, 5, 0, (u16)0xFFFE);
    registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, animData, 0);

    u8* mode = (u8*)g_GameGlobal->m_modeMelee;
    if (mode != 0) {
        if ((((u32)mode[8] >> 2) & 0x3F) == 7) {
            if ((u32)mode[0x10] == 0x9F) {
                self->m_flag = 1;
            }
        }
    }
}
