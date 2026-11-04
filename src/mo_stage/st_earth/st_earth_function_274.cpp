#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct StageData {
    char pad[0x3C];
    u8 count;
};

class Ground_base {
public:
    char pad[0x3C];
};

class Ground : public Ground_base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void fn_66_9C(void*, int, int);
    virtual void v40();
    virtual void fn_66_A4(void*);
};

class Stage_base {
public:
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
    virtual void fn_66_1B4();
    virtual void fn_66_274();
    virtual void createObjPokeTrainer(void*, int, const char*, void*, void*);
    virtual void fn_66_2AC4();
    virtual void fn_66_2AC0();
    virtual void fn_66_2AB4();
    virtual void fn_66_2AAC();
    virtual void fn_66_2AA4();
    virtual void fn_66_29AC();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_66_26C();
    virtual void process();
    virtual void updateStagePositions();
    virtual void debugCollision();
    virtual void fn_66_2A9C();
    virtual void fn_66_2A94();
    virtual void getZoneLightSetIndex();
    virtual void fn_66_2A78();
    virtual void clearCameraParam();
    virtual void initCameraParam();
    virtual void startLoadLocalData();
    virtual void isLoadLocalData();
    virtual void entryLocalData();
    virtual void removeLocalData();
    virtual void fn_66_2A74();
    virtual void getFighterStartPos();
    virtual void getFighterReStartPos();
    virtual void fn_66_2ACC();
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
    virtual void fn_66_2A64();
    virtual void fn_66_2A6C();
    virtual void fn_66_2A5C();
    virtual void fn_66_2A54();
    virtual void fn_66_2A4C();
    virtual void fn_66_2A38();
    virtual void fn_66_2A28();
    virtual void fn_66_2A1C();
    virtual void fn_66_2A10();
    virtual void fn_66_2A08();
    virtual void fn_66_2A00();
    virtual void fn_66_29F8();
    virtual void fn_66_29F4();
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
    virtual void fn_66_29EC();
    virtual void fn_66_29E4();
    virtual void fn_66_29DC();
    virtual void isAppear();
    virtual void isStartAppearTimming();
    virtual void getMadeinAiData();
    virtual void fn_66_2ADC();
    virtual void getBamperVector();
    virtual void notifyEventInfoReady();
    virtual void notifyEventInfoGo();
    virtual void getDestroyBossParamCommon();
    virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit();
    virtual void setStageInEffectInit();
    virtual void fn_66_29D4();
    virtual void fn_66_29CC();
    virtual void fn_66_29C8();
    virtual void getZoneState();
    virtual void getZonePos();
    virtual void getMagmaHeight();
    virtual void getAcidHeight();
    virtual void getIteamDropStatus();
    virtual void createWind2ndOnly();
    virtual void fn_66_2AD4();
    virtual void updateWind2ndOnly();
    virtual void setVision();
    virtual void fn_66_11BC();
    virtual void setCameraLimitRange();
    virtual void resetCameraLimitRange();
    virtual void checkChangeScene();
    virtual void resetChangeScene();
    virtual void setChangeSceneNumber();
    virtual void fn_66_6C8(int);
    virtual void fn_66_774(int);
    virtual void fn_66_860(int);
    virtual void fn_66_90C(int);
    virtual void fn_66_AC0();
    virtual void fn_66_BCC();
    virtual void fn_66_D28();
    virtual void fn_66_C5C();
    virtual void fn_66_DF4(int);
    virtual void fn_66_EAC(int);
    virtual void fn_66_F64(int);
    virtual void fn_66_10CC();
    virtual void fn_66_12B8();
    virtual void fn_66_181C();
    virtual void fn_66_1EB0();
    virtual void fn_66_2170();
    virtual void fn_66_24B4();
    virtual void fn_66_2680(void*);

    char padToUnk9C[0x5C];
    StageData* unk9C;
    char padA0[0x1C];
    void* ground;
    char padC0[0xE0];
    void* archive;
    char pad1A4[0xD4];
    char* unk278;
    char pad27C[0xC];
    char arc288[0x80];
    char arc308[0x40];
};

extern "C" {
void testStageParamInit__5StageFP9gfArchivei(void*, void*, int);
void testStageDataInit__5StageFP9gfArchiveii(void*, void*, int, int);
void createCollision__5StageFP9gfArchiveiP6Ground(void*, void*, int, void*);
void* getData__9gfArchiveF11ARCNodeTypeiPiUs(void*, int, int, int*, u16);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void setFileImage__9gfArchiveFPviQ25Heaps8HeapType(void*, void*, int, int);
void createStagePositions__5StageFPQ34nw4r3g3d7ResFile(void*, void*);
void createStagePositions__5StageFv(void*);
void loadStageAttrParam__5StageFP9gfArchivei(void*, void*, int);
void registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(void*, void*, u32);
void initPosPokeTrainer__5StageFii(void*, int, int);
void addGround__5StageFP6Ground(void*, Ground*);
u32 getGroundNum__5StageFv(void*);
Ground* getGround__5StageFi(void*, int);
Ground* fn_66_6860(int, void*, void*);
Ground* fn_66_12008(int, void*, void*);
void* __nwa__FUlQ25Heaps8HeapType(u32, int);
char* __construct_new_array(void*, void (*)(void), void*, u32, u32);
void fn_66_6C4(void);
extern char lbl_66_data_0[];
}

extern "C" void fn_66_274(Stage* self) {
    u8 cnt;
    char* base = lbl_66_data_0;
    u8 i;
    int size;
    void* data;
    StageData* sd;
    Ground* g;
    u32 n;
    u32 j;

    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2711, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(self->arc308, data, size, 0x11);
    }
    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(self->archive, 1, 0x2712, &size, (u16)0xFFFE);
    if (data != 0) {
        setFileImage__9gfArchiveFPviQ25Heaps8HeapType(self->arc288, data, size, 0x11);
    }
    testStageParamInit__5StageFP9gfArchivei(self, self->archive, 0xA);
    testStageDataInit__5StageFP9gfArchiveii(self, self->archive, 0x14, 0xDC);

    sd = self->unk9C;
    if (sd != 0) {
        self->unk278 = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(sd->count * 0x58 + 0x10, 0xF), fn_66_6C4, 0, 0x58, sd->count);
        if (self->unk278 != 0) {
            cnt = sd->count;
            for (i = 0; i != cnt; i++) {
                self->fn_66_2680(self->unk278 + i * 0x58);
            }
            addGround__5StageFP6Ground(self, fn_66_6860(4, base + 8, base + 0xC));
            addGround__5StageFP6Ground(self, fn_66_12008(8, base + 8, base + 0x1C));
            j = 0;
            n = getGroundNum__5StageFv(self);
            for (; j != n; j++) {
                g = getGround__5StageFi(self, j);
                if (g != 0) {
                    g->fn_66_9C(self->archive, 0, 0);
                    g->fn_66_A4(self->unk9C);
                }
            }
            self->fn_66_6C8(2);
            self->fn_66_774(3);
            self->fn_66_860(4);
            self->fn_66_90C(5);
            self->fn_66_90C(6);
            self->fn_66_90C(7);
            createCollision__5StageFP9gfArchiveiP6Ground(self, self->archive, 2, 0);
            self->fn_66_EAC(8);
            self->fn_66_DF4(9);
            self->fn_66_F64(0xA);
            self->fn_66_F64(0xB);
            self->fn_66_F64(0xC);
            self->fn_66_F64(0xD);
            self->fn_66_AC0();
            self->fn_66_BCC();
            self->fn_66_10CC();
            self->initCameraParam();
            data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 2, 0x64, (u16)0xFFFE);
            if (data != 0) {
                void* posData = data;
                createStagePositions__5StageFPQ34nw4r3g3d7ResFile(self, &posData);
            } else {
                createStagePositions__5StageFv(self);
            }
            self->createWind2ndOnly();
            loadStageAttrParam__5StageFP9gfArchivei(self, self->archive, 0x1E);
            data = getData__9gfArchiveF11ARCNodeTypeiUs(self->archive, 5, 0, (u16)0xFFFE);
            registScnAnim__5StageFPQ34nw4r3g3d11ResFileDataUl(self, data, 0);
            initPosPokeTrainer__5StageFii(self, 1, 0);
            self->createObjPokeTrainer(self->archive, 0x65, base + 0x28, self->ground, 0);
        }
    }
}
