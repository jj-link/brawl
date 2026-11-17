#pragma force_active on
typedef unsigned char u8;

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36();
    virtual void startup(void*, int, int);
    virtual void v38();
    virtual void f39(void*);
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
    virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
    virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128();
    virtual void f129(void*);
    virtual void f130(void*);
    virtual void f131(void*);
    virtual void f132(void*);
    virtual void f133(int);
};

struct Entry {
    char pad[0x24];
    u8 flag;
    char pad2[3];
};

struct Param {
    char pad[0x20];
    float a;
    float b;
};

struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
    virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition();
    virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch();
    virtual void processHit(); virtual void processCamera(); virtual void processFixCamera();
    virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
    virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu();
    virtual void processDebug(); virtual void renderDebug(); virtual void init();
    virtual void fn_68_350(); virtual void fn_68_4C4(); virtual void createObjPokeTrainer();
    virtual void fn_68_2254(); virtual void fn_68_2250(); virtual void fn_68_2244();
    virtual void fn_68_223C(); virtual void fn_68_2234(); virtual void fn_68_2120();
    virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac();
    virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage();
    virtual void renderDebugPositions(); virtual void fn_68_4BC(); virtual void process();
    virtual void updateStagePositions(); virtual void debugCollision(); virtual void fn_68_222C();
    virtual void fn_68_2224(); virtual void getZoneLightSetIndex(); virtual void fn_68_2208();
    virtual void clearCameraParam(); virtual void initCameraParam(); virtual void startLoadLocalData();
    virtual void isLoadLocalData(); virtual void entryLocalData(); virtual void removeLocalData();
    virtual void fn_68_2204(); virtual void getFighterStartPos(); virtual void getFighterReStartPos();
    virtual void fn_68_225C(); virtual void getPokeTrainerStartPos(); virtual void getItemPosCount();
    virtual void getItemPos(); virtual void getRandItemPos(); virtual void getKirifudaPos();
    virtual void getKirifudaAngle(); virtual void getKirifudaScale(); virtual void getKirifudaModelType();
    virtual void getPokeTrainerPosCount(); virtual void getPokeTrainerPos();
    virtual void getFighterDeadEffectSizeRate(); virtual void getEnemyDeadEffectSizeRate();
    virtual void getEnableZ(); virtual void fn_68_21F4(); virtual void fn_68_21FC();
    virtual void fn_68_21EC(); virtual void fn_68_21E4(); virtual void fn_68_21DC();
    virtual void fn_68_21C8(); virtual void fn_68_21B8(); virtual void fn_68_21AC();
    virtual void fn_68_21A0(); virtual void fn_68_2198(); virtual void fn_68_2190();
    virtual void fn_68_2188(); virtual void fn_68_2184(); virtual void isEnd();
    virtual void isEventEnd(); virtual void enableDevil(); virtual void disableDevil();
    virtual void isDevil(); virtual void setDevilScrool(); virtual void getLucarioFinalTechniquePosition();
    virtual void startAppear(); virtual void setAppearKind(); virtual void endAppear();
    virtual void getAppearTask(); virtual void forceStopAppear(); virtual void fn_68_2274();
    virtual void setMotionRatio(); virtual void saveMotionRatio(); virtual void restoreMotionRatio();
    virtual void setMotionSubRatio(); virtual void saveMotionSubRatio(); virtual void restoreMotionSubRatio();
    virtual void fn_68_217C(); virtual void fn_68_2174(); virtual void fn_68_216C();
    virtual void isAppear(); virtual void isStartAppearTimming(); virtual void getMadeinAiData();
    virtual void fn_68_226C(); virtual void getBamperVector(); virtual void notifyEventInfoReady();
    virtual void fn_68_2114(); virtual void getDestroyBossParamCommon(); virtual void stAdventureEventGetItem();
    virtual void setStageOutEffectInit(); virtual void setStageInEffectInit(); virtual void fn_68_2164();
    virtual void fn_68_215C(); virtual void fn_68_2158(); virtual void getZoneState();
    virtual void getZonePos(); virtual void getMagmaHeight(); virtual void getAcidHeight();
    virtual void getIteamDropStatus(); virtual void createWind2ndOnly(); virtual void fn_68_2264();
    virtual void updateWind2ndOnly(); virtual void setVision(); virtual void fn_68_17CC();
    virtual void setCameraLimitRange(); virtual void resetCameraLimitRange(); virtual void checkChangeScene();
    virtual void resetChangeScene(); virtual void setChangeSceneNumber(); virtual void fn_68_810();
    virtual void fn_68_9C4(); virtual void fn_68_B60(); virtual void fn_68_D60();
    virtual void fn_68_F58(); virtual void fn_68_1150(); virtual void fn_68_13FC();
    virtual void fn_68_15BC(); virtual void fn_68_170C(); virtual void fn_68_1870();
    virtual void fn_68_18CC(); virtual void fn_68_199C(); virtual void fn_68_1C8C();
    virtual void fn_68_1D30();
    virtual void fn_68_1E14(void*);
    virtual void fn_68_1E68();
    virtual u8 fn_68_1EC8();
    char pad40[0x5c];
    Param* f9c;
    char padA0[0x100];
    void* f1a0;
    char pad1A4[0x34];
    char f1d8;
    char pad1D9[0x113];
    char f2ec;
    char pad2ED[0x10B];
    char f3f8;
    char pad3F9[0x2f];
    Entry* f428;
};

extern "C" {
extern char lbl_68_data_0[];
Ground* fn_68_E754(int, const char*, const char*);
Ground* fn_68_FFFC(int, const char*, const char*);
float randf__Fv();
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_68_1F24(Stage* stage) {
    Param* p = stage->f9c;
    char* data = lbl_68_data_0;
    if (p) {
        u8 kind = stage->fn_68_1EC8();
        if (kind != 0xff) {
            Ground* ground;
            float sum = p->a + p->b;
            if (sum * randf__Fv() < p->a) {
                ground = fn_68_E754(3, data + 0x1c8, data + 0x1d8);
            } else {
                ground = fn_68_FFFC(4, data + 0x1e8, data + 0x1f8);
            }
            if (ground) {
                addGround__5StageFP6Ground(stage, ground);
                ground->startup(stage->f1a0, 0, 0);
                ground->f39(stage->f9c);
                stage->fn_68_1E14(&stage->f428[kind]);
                stage->f428[kind].flag = 0;
                ground->f129(stage->f428);
                ground->f130(&stage->f2ec);
                ground->f131(&stage->f3f8);
                ground->f132(&stage->f1d8);
                ground->f133(kind);
            }
        }
    }
}
}
