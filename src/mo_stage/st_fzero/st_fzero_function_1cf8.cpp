#include <gf/gf_archive.h>
#include <st/st_positions.h>
#pragma force_active on

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
    virtual void fn_61_248();
    virtual void fn_61_2C8();
    virtual void createObjPokeTrainer();
    virtual void fn_61_21E4();
    virtual void fn_61_21E0();
    virtual void fn_61_21D4();
    virtual void fn_61_21CC();
    virtual void fn_61_21C4();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_61_2C0();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_61_21BC();
    virtual void fn_61_21B4();
    virtual void getZoneLightSetIndex();
    virtual void fn_61_2198();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_61_2194();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_61_21EC();
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
    virtual void fn_61_2184();
    virtual void fn_61_218C();
    virtual void fn_61_217C();
    virtual void fn_61_2174();
    virtual void fn_61_216C();
    virtual void fn_61_2158();
    virtual void fn_61_2148();
    virtual void fn_61_213C();
    virtual void fn_61_2130();
    virtual void fn_61_2128();
    virtual void fn_61_2120();
    virtual void fn_61_2118();
    virtual void fn_61_2114();
    virtual void isEnd();
    virtual void fn_61_2070();
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
    virtual void fn_61_21FC();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_61_210C();
    virtual void fn_61_2104();
    virtual void fn_61_20FC();
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
    virtual void fn_61_20F4();
    virtual void fn_61_20EC();
    virtual void fn_61_20E8();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_61_21F4();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_61_1618();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_61_5C8();
    virtual void fn_61_708();
    virtual void fn_61_7E0();
    virtual void fn_61_8B8();
    virtual void fn_61_AEC();
    virtual void fn_61_C2C();
    virtual void fn_61_D58();
    virtual void fn_61_F40();
    virtual void fn_61_106C();
    virtual void fn_61_11D8();
    virtual void fn_61_1230();
    virtual void fn_61_17B4();
    virtual void fn_61_1810();
    virtual void fn_61_1CF8();
    virtual void fn_61_1E3C();
    virtual unsigned int fn_61_20C0();
    char pad40[0x50];
    stPositions* positions;
    char pad94[0x10c];
    gfArchive* archive;
    char pad1a4[0x3c];
    unsigned char ready;
    char pad1e1[0x79b];
    unsigned char state;
};

extern "C" void fn_61_1CF8(Stage* self) {
    switch (self->state) {
    case 0:
        self->state = 1;
    case 1:
        switch (self->ready) {
        case 2:
        if (self->fn_61_20C0() == 1U) {
            void* data = self->archive->getData(Data_Type_Model, 0x65, 0xfffe);
            if (data) {
                nw4r::g3d::ResFile file(data);
                self->positions->loadPositionData(&file);
            }
            self->updateStagePositions();
            self->state = 3;
        }
        break;
        }
        break;
    case 2:
        break;
    case 3:
        if (self->fn_61_20C0() == 0) {
            void* data = self->archive->getData(Data_Type_Model, 0x64, 0xfffe);
            if (data) {
                nw4r::g3d::ResFile file(data);
                self->positions->loadPositionData(&file);
            }
            self->updateStagePositions();
            self->state = 1;
        }
        break;
    }
}
