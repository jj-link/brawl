#pragma force_active on

class gfTask;

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
    virtual void dtor();
    virtual void createObj();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer();
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
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
    virtual void getAppearTask();
    virtual void forceStopAppear();
    virtual void getFinalTechniqColor();
    virtual void setMotionRatio(float, float);
    virtual void saveMotionRatio(void*);
};

extern "C" {
extern void* lbl_27_bss_F0;
extern float lbl_27_rodata_EF4;
extern const char* lbl_27_data_18698[2];
extern void* lbl_8059FF90;
extern void* lbl_805A0360;
void* getTask__6gfTaskFi(int id);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* fn_27_5BCD0(void* p);
unsigned int fn_27_5BEA8(void* p);
void* getInstance__15gfTaskSchedulerFv();
void setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(void* sched, int cat, bool b);
void* getTask__15gfTaskSchedulerFPCc(void* sched, const char* name);
void setPaused__6gfTaskFb(void* task, bool b);
}

extern Stage* lbl_27_bss_5668;

extern "C" void fn_27_C6C28(void* self) {
    unsigned char* p = (unsigned char*)self;
    unsigned int id = *(unsigned int*)(p + 0x44);
    int flag;
    if (id + 0x10000 == 0xFFFF) {
        flag = 0;
    } else {
        flag = getTask__6gfTaskFi(id) != 0;
    }
    if (flag == 0) {
        if (p[0x8E] != 0) {
            p[0x8D] = 1;
        }
    } else if (p[0x8C] != 0) {
        if (lbl_27_bss_F0 == 0) {
            void* s = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
            if (s != 0) {
                s = fn_27_5BCD0(s);
            }
            lbl_27_bss_F0 = s;
        }
        if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0xB, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0xA, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0xC, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0x6, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0x21, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0x9, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0xE, true);
            setPauseCategory__15gfTaskSchedulerFQ26gfTask8Categoryb(getInstance__15gfTaskSchedulerFv(), 0xF, true);
            ((unsigned char*)lbl_8059FF90)[0x74] = 1;
            ((unsigned char*)lbl_805A0360)[0x41] = 1;
            if (lbl_27_bss_5668 != 0) {
                lbl_27_bss_5668->saveMotionRatio(p + 0x7C);
                lbl_27_bss_5668->setMotionRatio(lbl_27_rodata_EF4, lbl_27_rodata_EF4);
            }
            int i;
            void* sched = getInstance__15gfTaskSchedulerFv();
            const char** names = lbl_27_data_18698;
            i = 0;
            do {
                void* t = getTask__15gfTaskSchedulerFPCc(sched, *names);
                if (t != 0) {
                    setPaused__6gfTaskFb(t, true);
                }
                i++;
                names++;
            } while (i < 2);
            p[0x8C] = 0;
            p[0x8E] = 1;
        }
    }
}
