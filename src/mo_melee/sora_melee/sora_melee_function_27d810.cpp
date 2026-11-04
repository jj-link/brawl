#pragma force_active on
#include <ft/ft_manager.h>
#include <cm/cm_camera_controller.h>

extern "C" {
extern char* g_IfMngr;
void fn_800E3684(void*, int);
void fn_800E19EC(void*, int);
void fn_8009C9B8(void*, unsigned int);
}
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base { public:
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
virtual void destructor();
virtual void createObj();
virtual void createObjPokeTrainer();
virtual void getPokeTrainerPointNum();
virtual int getPokeTrainerPointData();
virtual void getPokeTrainerPositionZ();
virtual void getPokeTrainerDrawLayer();
virtual void isAdventureStage();
virtual void getItemPac();
virtual void getItemGenPac();
virtual void getItemPacEnemyFigure();
virtual int getEnemyPac(int, int, int);
virtual void getAdvRadarData();
virtual void initializeStage();
virtual void closeStage();
virtual void renderDebugPositions();
virtual void loading();
virtual void process();
virtual void updateStagePositions();
virtual void debugCollision();
virtual void getAIRange();
virtual void getDefaultLightSetIndex();
virtual void getZoneLightSetIndex();
virtual void getScrollDir();
virtual void clearCameraParam();
virtual void initCameraParam();
virtual void startLoadLocalData();
virtual void isLoadLocalData();
virtual void entryLocalData();
virtual void removeLocalData();
virtual void appearanceFighterLocal();
virtual void getFighterStartPos();
virtual void getFighterReStartPos();
virtual void isReStartSamePoint();
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
virtual void getBgmID();
virtual void getBgmID_2();
virtual void getNowStepBgmID();
virtual void getBgmOptionID();
virtual void isBgmChange();
virtual void getBgmChangeID();
virtual void setBgmChange();
virtual void getBgmVolume();
virtual void getBgmPlayOffsetFrame();
virtual void isNextStepBgmEqualNowStepBgmFromFlag();
virtual void setFrameRuleTime();
virtual void getFrameRuleTime();
virtual void notifyTimmingGameStart();
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
char pad40[8];
float value;
};
extern Stage* lbl_27_bss_5668;
struct Player { char pad[0x5c]; };
struct Data { char pad[9]; unsigned char mode; char padA; unsigned char flagB; };
class Self {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual int slot43();
char pad04[8];
Data* data;
Stage* entries[8];
Stage* module;
unsigned char flags;
char pad35[3];
unsigned int id;
};

inline int decrement(Self* self, int playerNo) {
    int off = playerNo * 0x5c;
    signed char c = *(signed char*)((char*)self->data + off + 0x9c);
    if (c != 0) *(signed char*)((char*)self->data + off + 0x9c) = c - 1;
    int v;
    int c2 = *(signed char*)((char*)self->data + off + 0x9c);
    v = c2;
    if (v < 0) v = 0;
    if (self->slot43() != 0 && ((self->flags >> 5) & 1) != 0) {
        fn_800E19EC(*(void**)(g_IfMngr + *(unsigned char*)((char*)self->data + off + 0x9a) * 4 + 0x4c), v);
    }
    return c2 != 0;
}
extern "C" void fn_27_27D810(Self* self, int entryId, int u1, int u2, int arg7) {
    int result = 0;
    int playerNo = g_ftManager->getPlayerNo(entryId);
    if (self->slot43() != 0 && ((self->data->flagB >> 1) & 1) == 0 &&
        ((self->flags >> 5) & 1) != 0 && (!self->module || !self->module->getPokeTrainerPointData())) {
        int off = playerNo * 0x5c;
        unsigned char idx = *(unsigned char*)((char*)self->data + off + 0x9a);
        unsigned char b = *(unsigned char*)(g_IfMngr + idx + 0x68);
        fn_800E3684(*(void**)(g_IfMngr + (b << 2) + 0x4c), 2);
    }
    if (self->module) {
        result = self->module->getEnemyPac(entryId, playerNo, arg7);
    } else if ((unsigned int)((self->data->mode >> 5) & 7) == 1) {
        if (decrement(self, playerNo)) result = 1;
    } else {
        result = 1;
    }
    if (result && arg7 >= 0) {
        self->entries[playerNo]->value = (float)arg7;
        self->entries[playerNo]->createObj();
    } else {
        fn_8009C9B8(CameraController::getInstance(), playerNo);
    }
    if (lbl_27_bss_5668 && self->id == (unsigned int)entryId) {
        lbl_27_bss_5668->endAppear();
    }
}
