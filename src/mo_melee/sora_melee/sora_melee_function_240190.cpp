#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(u32, int);
void* __ct__9gfArchiveFv(void*);
void __dt__9gfArchiveFv(void*, int);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void*, int, int, int*, u16);
u32 fn_800151FC(void*, void*, int, int, int, int);
void fn_27_240488(void*);
}

struct gfTask_base { char pad[0x3c]; };

class gfTask : public gfTask_base {
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
    virtual void slot22();
    virtual void slot23();
    virtual void createObjPokeTrainer();
    virtual void getPokeTrainerPointNum();
    virtual void getPokeTrainerPointData();
    virtual void getPokeTrainerPositionZ();
    virtual void getPokeTrainerDrawLayer(void* p);
    virtual void isAdventureStage();
    virtual void getItemPac();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void slot38();
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
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void getKirifudaPos();
    virtual void getKirifudaAngle();
    virtual void getKirifudaScale();
    virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount();
    virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate();
    virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ();
    virtual void slot69();
    virtual void getBgmID();
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
    virtual void slot94();
    virtual void setMotionRatio();
    virtual void saveMotionRatio();
    virtual void restoreMotionRatio();
    virtual void setMotionSubRatio();
    virtual void saveMotionSubRatio();
    virtual void restoreMotionSubRatio();
    virtual void isCameraLocked();
    virtual void isBossBattleMode();
    virtual void isSimpleBossBattleMode();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void slot107();
    virtual void getBamperVector();
    virtual void slot109();
    virtual void slot110();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void helperStarWarp();
    virtual void initializeFighterAttackRatio();
    virtual void startFighterEvent();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_27_22C25C();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void slot127();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual u32 checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber(u8 n);

    void* p40;
    u8 state;
    u8 pad45;
    u8 enabled;
    u8 flag47;
    char pad48[0x54];
    void* arc9c;
    void* arca0;
    char padA4[0x20];
    gfTask* other;
    char padC8[4];
    u8 unkCC;
    u8 unkCD;
    u8 flagCE;
    u8 idxCF;
    u8 countD0;
};

extern "C" void fn_27_240190(gfTask* self) {
    if (self->enabled != 0) {
        switch (self->state) {
        case 0:
            if (self->flag47 != 1 && ((self->flagCE >> 7) & 1) != 1U) {
                u16 id = *(u16*)((char*)self->p40 + 0x1A);
                if (id == 0x13 || id == 0x19) {
                    self->state = 1;
                }
            }
            break;
        case 1:
            if (self->arc9c == 0) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x80, 0x11);
                if (p != 0) {
                    p = __ct__9gfArchiveFv(p);
                }
                self->arc9c = p;
            }
            {
                u8* base = (u8*)self + self->idxCF;
                self->unkCC = base[0xD1];
                self->getPokeTrainerDrawLayer(base);
            }
            if (fn_800151FC(self->arc9c, self->pad48, 0x11, 0, 0, 0xFF) == 1) {
                void* q = __nw__FUlQ25Heaps8HeapType(0x80, 0x11);
                if (q != 0) {
                    q = __ct__9gfArchiveFv(q);
                }
                self->arca0 = q;
                self->state = 2;
                return;
            }
            break;
        case 2:
            if ((((u8*)self->arc9c)[9] >> 7) & 1) {
                int size;
                void* data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->arc9c, 1, 1, &size, 0xFFFE);
                setFileImage__9gfArchiveFPviQ25Heaps8HeapType(self->arca0, data, size, 0x11);
                self->state = 3;
                return;
            }
            break;
        case 3:
            if (self->other != 0) {
                *(void**)((char*)self->other + 0x1A8) = self->arca0;
                self->other->setChangeSceneNumber(self->unkCC);
                if (self->other->checkChangeScene() == 1 || self->flag47 == 1 ||
                    (int)self->unkCD != (int)*(u16*)((char*)self->p40 + 0x1A) ||
                    self->unkCC != ((u8*)self + self->idxCF)[0xD1]) {
                    self->state = 5;
                    *(void**)((char*)self->other + 0x1A8) = 0;
                    self->other->resetChangeScene();
                    u8 count = self->countD0;
                    if (++self->idxCF >= count) {
                        fn_27_240488(self);
                        return;
                    }
                }
            } else if (self->flag47 == 1 ||
                       (int)self->unkCD != (int)*(u16*)((char*)self->p40 + 0x1A) ||
                       self->unkCC != ((u8*)self + self->idxCF)[0xD1]) {
                self->state = 5;
            }
            break;
        case 5:
            if (self->arc9c != 0) {
                __dt__9gfArchiveFv(self->arc9c, 1);
            }
            if (self->arca0 != 0) {
                __dt__9gfArchiveFv(self->arca0, 1);
            }
            self->arc9c = 0;
            self->arca0 = 0;
            if (self->flag47 == 1) {
                self->state = 6;
                return;
            }
            self->state = 0;
            break;
        }
    }
}
