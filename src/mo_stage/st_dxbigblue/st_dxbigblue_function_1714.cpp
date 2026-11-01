#pragma force_active on

#include <mt/mt_vector.h>

extern "C" const float lbl_81_rodata_0[];
extern "C" float randf__Fv();

struct SpawnEntry {
    Vec3f pos;
    Vec3f alt;
};

struct Entry {
    char pad[8];
    unsigned char index;
};

struct Bounds {
    char pad[4];
    float bottom;
    float top;
};

struct Stage_base {
    char pad[0x3c];
};

struct Stage : Stage_base {
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
    virtual void fn_81_984();
    virtual void fn_81_ABC();
    virtual void fn_81_C04();
    virtual void fn_81_D20();
    virtual void fn_81_DFC();
    virtual void fn_81_ED8();
    virtual void fn_81_11BC();
    virtual void fn_81_130C();
    virtual void fn_81_153C();
    virtual void fn_81_1598();
    virtual void fn_81_16A4();
    virtual void fn_81_1714();
    virtual void fn_81_191C();
    virtual void fn_81_19A8();
    virtual void fn_81_1C84();
    virtual void fn_81_1DE4();
    virtual void fn_81_21EC();
    virtual void fn_81_22DC();
    virtual void fn_81_245C();
    virtual void fn_81_25C4();
    virtual void fn_81_293C();
    virtual void fn_81_2CA0();
    virtual void fn_81_2DB4();
    virtual void fn_81_31C0();
    virtual void fn_81_344C();
    virtual void fn_81_37E0();
    virtual void fn_81_387C();
    virtual void fn_81_3900();
    virtual void fn_81_399C();
    virtual void fn_81_3B04();
    virtual void fn_81_3C1C();
    virtual void fn_81_3CFC(unsigned char p1, void* p2);
    virtual void fn_81_3D74();
    virtual void fn_81_3DEC();
    virtual void fn_81_3E54();
    virtual int fn_81_3ED0(unsigned char p1, void* p2);
    virtual void fn_81_3F00();
    virtual Entry* fn_81_3F08(void* p1);

    char pad[0x1f0];
    SpawnEntry entries[12];
    unsigned char result[12];
    char pad3[4];
    char unk360[0x20];
};

extern "C" void fn_81_1714(Stage* self) {
    const float* L = lbl_81_rodata_0;
    Entry* cur = self->fn_81_3F08(self->unk360);
    if (cur == 0)
        return;

    unsigned char idx = cur->index;
    Vec3f pos;
    pos = self->entries[idx].pos;

    if (pos.m_x > *reinterpret_cast<float*>(reinterpret_cast<char*>(self) + 0x1EC))
        return;

    unsigned char choice;
    if (idx == 11) {
        choice = 1;
    } else {
        Bounds* bounds = *reinterpret_cast<Bounds**>(reinterpret_cast<char*>(self) + 0x9C);
        if (bounds == 0)
            return;

        choice = (unsigned char)(L[4] * randf__Fv());
        if (self->fn_81_3ED0(choice, self->unk360) != 0)
            return;

        pos = self->entries[cur->index].alt;

        switch (choice) {
        case 4:
            if (pos.m_y > L[5])
                return;
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x1F8) = 0;
            break;
        case 0:
        case 7:
        case 8:
            if (!(pos.m_y <= bounds->top))
                break;
            return;
        case 2:
        case 3:
        case 9:
        case 10:
            if (pos.m_y >= bounds->bottom)
                return;
            break;
        default:
            break;
        }

        if (cur->index == 4 &&
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x1F8) == 0)
            return;

        pos.m_y = pos.m_y + (self->entries[choice].alt.m_y - self->entries[choice].pos.m_y);

        if (pos.m_y < L[0])
            return;
        if (pos.m_y > L[6])
            return;
    }

    Entry* next = self->fn_81_3F08(self->unk360);
    if (next == 0)
        return;

    self->fn_81_3CFC(choice, self->unk360);
    self->result[choice] = next->index;
}
