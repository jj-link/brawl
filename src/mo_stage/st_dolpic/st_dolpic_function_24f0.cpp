#include <revolution/OS/OSFastCast.h>
#include <gr/ground.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" {
    extern const float lbl_46_rodata_0[];
    extern char lbl_46_data_0[];
    float fn_801622C4(float);
    float fn_8016232C(float);
}

struct StageParameters {
    float start;
    char pad[8];
    float length;
    float transition;
};

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
    virtual void fn_46_3FEC();
    virtual void init();
    virtual void fn_46_280();
    virtual void fn_46_354();
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
    virtual void setCameraLimitRange(float, float, float, float);
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_46_688();
    virtual void fn_46_6EC();
    virtual void fn_46_8F0();
    virtual void fn_46_9BC();
    virtual void fn_46_C40();
    virtual void fn_46_CF8();
    virtual void fn_46_E28();
    virtual void fn_46_F58();
    virtual void fn_46_1110();
    virtual void fn_46_116C();
    virtual void fn_46_1EE8();
    virtual void fn_46_22FC();
    virtual void fn_46_24F0();
    virtual void fn_46_2940();
    virtual void fn_46_3398();
    virtual void fn_46_34C8();
    virtual void fn_46_3704();
    virtual void fn_46_39F0();
    virtual void fn_46_3CD4();
    virtual void fn_46_4070(unsigned char, float);

    char pad40[0x5c];
    StageParameters* parameters;
    char padA0[0x138];
    unsigned char scene;
    char pad1D9[3];
    float position;
    char pad1E0[0x14];
    unsigned char current;
    unsigned char state[1];
};

extern "C" Ground* getGround__5StageFi(Stage*, int);

extern "C" void fn_46_24F0(
    Stage* self, unsigned char index, unsigned int enter, unsigned int leave)
{
    StageParameters* params = self->parameters;
    char* data;
    const float* constants = lbl_46_rodata_0;
    data = lbl_46_data_0;
    if (params == 0)
        return;

    if (self->current != 5)
        index = self->current;

    float start = params->start;
    float transition = params->transition;
    float position = self->position;
    float end = start + params->length - transition;
    float amount;
    int mode;

    if (position > end) {
        mode = 1;
        amount = constants[1] - (position - end) / transition;
    } else if (position > start + transition) {
        amount = constants[1];
        mode = 2;
    } else if (position > start) {
        mode = 3;
        amount = constants[1] - (position - start) / transition;
    } else {
        mode = 4;
        amount = constants[0];
    }

    if (amount < constants[0])
        amount = constants[0];
    if (amount > constants[1])
        amount = constants[1];

    unsigned short angle = (unsigned short)(constants[6] * amount);
    float value = fn_801622C4(constants[7] * __OSu16tof32(&angle));

    switch (mode) {
    case 0:
        break;

    case 1:
        if (enter == 1) {
            self->state[0] = 0;
            self->state[index] = 0;
            self->fn_46_4070(index, value);
        } else {
            self->fn_46_4070(index, constants[1]);
        }
        self->current = index;
        break;

    case 2: {
        Ground* ground = getGround__5StageFi(self, 0);
        if (ground == 0)
            break;
        switch (self->scene) {
        case 10:
        case 12:
            ground->setNodeVisibility(true, 0, data + 0x51c, false, false);
            break;
        case 26:
        case 28:
            ground->setNodeVisibility(true, 0, data + 0x534, false, false);
            self->resetCameraLimitRange();
            break;
        case 32:
            ground->setNodeVisibility(true, 0, data + 0x54c, false, false);
            break;
        }
        self->current = index;
        self->fn_46_4070(index, value);
        break;
    }

    case 3: {
        if (leave == 1) {
            self->state[0] = 2;
            self->state[index] = 2;
            self->fn_46_4070(index, constants[1] - value);
        } else {
            self->fn_46_4070(index, constants[1]);
        }

        Ground* ground = getGround__5StageFi(self, 0);
        if (ground == 0)
            break;
        switch (self->scene) {
        case 4:
            ground->setNodeVisibility(false, 0, data + 0x51c, false, false);
            break;
        case 18:
        case 20: {
            ground->setNodeVisibility(false, 0, data + 0x534, false, false);
            data = reinterpret_cast<char*>(&CameraController::getInstance()->m_stageCameraParam);
            float limit;
            if (data != 0) {
                float cosine = fn_8016232C(constants[8]);
                limit = constants[9] -
                    constants[10] *
                    (reinterpret_cast<cmStageParam*>(data)->m_verticalRotationFactor *
                     (fn_801622C4(constants[8]) / cosine));
            }
            self->setCameraLimitRange(
                constants[11], constants[12], constants[13], limit);
            break;
        }
        case 24:
        case 28:
            ground->setNodeVisibility(false, 0, data + 0x54c, false, false);
            break;
        }
        break;
    }

    case 4:
        if (leave == 1) {
            self->fn_46_4070(index, constants[0]);
            self->current = 5;
        }
        break;
    }
}
