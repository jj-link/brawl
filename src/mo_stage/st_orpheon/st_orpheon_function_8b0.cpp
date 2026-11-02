#pragma force_active on

#include <gr/gr_tengan_event.h>
#include <st/se_util.h>
#include <gf/gf_archive.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>

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
    virtual void fn_55_290();
    virtual void fn_55_36C();
    virtual void createObjPokeTrainer();
    virtual void fn_55_2388();
    virtual void fn_55_2384();
    virtual void fn_55_2378();
    virtual void fn_55_2370();
    virtual void fn_55_2368();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_55_364();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_55_2360();
    virtual void fn_55_2358();
    virtual void getZoneLightSetIndex();
    virtual void fn_55_233C();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_55_2338();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_55_2390();
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
    virtual void fn_55_2328();
    virtual void fn_55_2330();
    virtual void fn_55_2320();
    virtual void fn_55_2318();
    virtual void fn_55_2310();
    virtual void fn_55_22FC();
    virtual void fn_55_22EC();
    virtual void fn_55_22E0();
    virtual void fn_55_22D4();
    virtual void fn_55_22CC();
    virtual void fn_55_22C4();
    virtual void fn_55_22BC();
    virtual void fn_55_22B8();
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
    virtual void fn_55_23A0();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void fn_55_22B0();
    virtual void fn_55_22A8();
    virtual void fn_55_22A0();
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
    virtual void fn_55_2298();
    virtual void fn_55_2290();
    virtual void fn_55_228C();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_55_2398();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_55_1C24();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_55_21E0(int);
};

struct GroundObjectBase {
    char pad[0x3c];
};

class GroundObject : public GroundObjectBase {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void setVisibility(int, int, int, int);
};

class ConcreteSeSeq : public StSeUtil::SeSeq {
public:
    virtual ~ConcreteSeSeq();
};

struct StOrpheon {
    char pad0[0x90];
    void* positions;
    char pad94[0x10c];
    gfArchive* archive;
    char pad1a4[0x18c];
    grTenganEvent event;
    char pad3dc[0x204];
    float angle;
    float targetAngle;
    float progress;
    float progress2;
    char pad5f0[0x18];
    float f608;
    float f60c;
    float f610;
    ConcreteSeSeq seq614;
    char pad634[0x54];
    ConcreteSeSeq seq688;
    char pad6a8[0x1c];
    unsigned char motion;
    unsigned char triggered : 1;
    unsigned char alternate : 1;
    unsigned char remainingFlags : 6;
};

extern "C" {
extern const float lbl_55_rodata_0[];

void fn_55_2124(void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, unsigned long);
void zoomOutCamera__7stMeleeFff(void*, float, float);
void zoomInCamera__7stMeleeFv(void*);
void playSeBasic__7stMeleeF5SndIDf(void*, int, float);
GroundObject* getGround__5StageFi(void*, int);
void setEnableCollisionStatus__6GroundFb(void*, bool);
void loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(void*, void*);
unsigned long randi__Fl(long);
void setMotion__8grMadeinFUl(void*, unsigned long);
void startEntity__8grMadeinFv(void*);
void startEntityAutoLoop__8grMadeinFv(void*);
bool isEndEntity__8grMadeinFv(void*);

void fn_55_8B0(StOrpheon* self, float delta) {
    const float* rd = lbl_55_rodata_0;
    Stage* stage = (Stage*)self;

    if (self->event.isEvent()) {
        switch (self->event.getPhase()) {
        case 0:
            if (self->event.isReadyEnd()) {
                registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(
                    self, self->archive->getData(Data_Type_Scene, 4, 0xfffe), 0);
                self->event.setPhase(self->event.getPhase() + 1);
                self->event.m_manualFramesLeft = rd[0];
            }
            break;

        case 1:
            self->seq688.playFrame(0, self->event.m_manualFramesLeft);
            self->event.m_manualFramesLeft += delta;
            if (self->event.m_manualFramesLeft >= rd[1]) {
                self->event.setPhase(self->event.getPhase() + 1);
                zoomOutCamera__7stMeleeFff(self, rd[7], rd[8]);
                stage->fn_55_21E0(0);
                self->event.m_manualFramesLeft = rd[0];
                registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(
                    self, self->archive->getData(Data_Type_Scene, 0, 0xfffe), 0);
            }
            break;

        case 2:
            self->event.setPhase(self->event.getPhase() + 1);
            break;

        case 3:
            self->event.m_manualFramesLeft += delta;
            if (self->event.m_manualFramesLeft >= rd[9]) {
                self->event.setPhase(self->event.getPhase() + 1);
                self->event.m_manualFramesLeft = rd[0];
                self->f608 = rd[0];
                self->f60c = rd[0];
                self->f610 = rd[0];
                playSeBasic__7stMeleeF5SndIDf(self, 0x1bd6, rd[0]);
                self->triggered = 0;
                fn_55_2124(self, 0);
            }
            break;

        case 4: {
            float difference = self->targetAngle - self->angle;
            if ((float)__fabs(difference) < rd[10] && !self->triggered) {
                self->triggered = 1;
                if (!self->alternate) {
                    GroundObject* ground = getGround__5StageFi(self, 0);
                    ground->setVisibility(0, 0, 1, 0);
                    ground = getGround__5StageFi(self, 0);
                    ground->setVisibility(1, 0, 8, 0);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 3), false);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 4), true);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 5), true);
                    self->alternate = 1;
                    void* raw = self->archive->getData(Data_Type_Model, 0x69, 0xfffe);
                    if (raw) {
                        void* data = raw;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(
                            self->positions, &data);
                    }
                    stage->updateStagePositions();
                } else {
                    GroundObject* ground = getGround__5StageFi(self, 0);
                    ground->setVisibility(1, 0, 1, 0);
                    ground = getGround__5StageFi(self, 0);
                    ground->setVisibility(0, 0, 8, 0);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 3), true);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 4), false);
                    setEnableCollisionStatus__6GroundFb(getGround__5StageFi(self, 5), false);
                    self->alternate = 0;
                    void* raw = self->archive->getData(Data_Type_Model, 0x64, 0xfffe);
                    if (raw) {
                        void* data = raw;
                        loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(
                            self->positions, &data);
                    }
                    stage->updateStagePositions();
                }
            }
            if ((float)__fabs(difference) > rd[11]) {
                float speed = difference / rd[12];
                speed *= delta;
                self->angle += speed;
            } else {
                self->angle = self->targetAngle;
                self->event.setPhase(self->event.getPhase() + 1);
                if (rd[0] == self->targetAngle) {
                    self->targetAngle = rd[1];
                    unsigned long random = randi__Fl(2);
                    if (random >= 1)
                        random = 1;
                    if (random == 0)
                        self->targetAngle *= rd[13];
                } else {
                    self->targetAngle = rd[0];
                }
                zoomInCamera__7stMeleeFv(self);
                stage->fn_55_21E0(1);
                fn_55_2124(self, 1);
                self->event.m_manualFramesLeft = rd[0];
            }
            break;
        }

        case 5:
            self->event.m_manualFramesLeft += delta;
            if (self->event.m_manualFramesLeft >= rd[9])
                self->event.setPhase(self->event.getPhase() + 1);
            break;

        case 6:
            if (rd[0] == self->targetAngle) {
                self->progress2 += rd[14] * delta;
                if (self->progress2 >= rd[1]) {
                    self->progress2 = rd[1];
                    self->event.setPhase(self->event.getPhase() + 1);
                    self->motion = 1;
                    setMotion__8grMadeinFUl(getGround__5StageFi(self, 2), self->motion);
                    startEntity__8grMadeinFv(getGround__5StageFi(self, 2));
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1bcf, rd[0]);
                }
            } else {
                self->progress2 -= rd[14] * delta;
                if (self->progress2 < rd[0]) {
                    self->progress2 = rd[0];
                    self->event.setPhase(self->event.getPhase() + 1);
                    self->motion = 1;
                    setMotion__8grMadeinFUl(getGround__5StageFi(self, 2), self->motion);
                    startEntity__8grMadeinFv(getGround__5StageFi(self, 2));
                }
            }
            break;

        case 7:
            if (rd[0] == self->targetAngle) {
                self->progress += rd[15] * delta;
                if (self->progress >= rd[16]) {
                    self->progress = rd[16];
                    if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 2))) {
                        self->event.setPhase(self->event.getPhase() + 1);
                        self->motion = 0;
                        setMotion__8grMadeinFUl(getGround__5StageFi(self, 2), self->motion);
                        startEntityAutoLoop__8grMadeinFv(getGround__5StageFi(self, 2));
                        playSeBasic__7stMeleeF5SndIDf(self, 0x1bd0, rd[0]);
                        self->seq614.playFrame(self->motion, rd[0], rd[0]);
                    }
                }
            } else {
                self->progress -= rd[15] * delta;
                if (self->progress < rd[0]) {
                    self->progress = rd[0];
                    if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, 2))) {
                        self->event.setPhase(self->event.getPhase() + 1);
                        self->motion = 0;
                        setMotion__8grMadeinFUl(getGround__5StageFi(self, 2), self->motion);
                        startEntityAutoLoop__8grMadeinFv(getGround__5StageFi(self, 2));
                        playSeBasic__7stMeleeF5SndIDf(self, 0x1bd0, rd[0]);
                        self->seq614.playFrame(self->motion, rd[0], rd[0]);
                    }
                }
            }
            break;

        case 8:
            self->event.end();
            break;
        }
        self->event.update(delta);
    }
}
}
