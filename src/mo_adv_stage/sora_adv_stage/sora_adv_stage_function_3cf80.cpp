#pragma force_active on
#include <st/st_trigger.h>

struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_40_2024();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void fn_40_21B8();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void fn_40_222C();
    virtual void renderPre();
    virtual void fn_40_8A84();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_40_12F8();
    virtual void fn_40_D24();
    virtual void createObjPokeTrainer();
    virtual void fn_40_5098();
    virtual void fn_40_50A0();
    virtual void fn_40_50BC();
    virtual void fn_40_8B18();
    virtual void fn_40_8B28();
    virtual void fn_40_7D94();
    virtual void fn_40_8154();
    virtual void fn_40_80AC();
    virtual void fn_40_8160();
    virtual void fn_40_8478();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_40_45C();
    virtual void process();
    virtual void fn_40_7D44();
    virtual void debugCollision();
    virtual void fn_40_6FF4();
    virtual void fn_40_8B10();
    virtual void getZoneLightSetIndex();
    virtual void fn_40_8AF4();
    virtual void clearCameraParam();
    virtual void fn_40_6C6C();
    virtual void fn_40_464();
    virtual void fn_40_5EC();
    virtual void fn_40_990();
    virtual void fn_40_A7C();
    virtual void fn_40_B98();
    virtual void fn_40_5FD8();
    virtual void fn_40_6050();
    virtual void isReStartSamePoint();
    virtual void getPokeTrainerStartPos();
    virtual void getItemPosCount();
    virtual void getItemPos();
    virtual void getRandItemPos();
    virtual void getKirifudaPos();
};

struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
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
    virtual void fn_40_3C660();
    virtual void fn_40_3D05C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void fn_40_3D660();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void fn_40_3C6C8();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid(unsigned long);
};

struct grGimmickWarpZone_base { char pad[0x3c]; };
class grGimmickWarpZone : public grGimmickWarpZone_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_40_37EA8();
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
    virtual void fn_40_37E50();
    virtual void update();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void getModelCount();
    virtual void startup();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid(unsigned long);
};

extern "C" void fn_40_3CF80(void* self) {
    char* s = (char*)self;
    if (!g_stTriggerMng->getTriggerFlag(
            (stTriggerData*)(*(char**)(s + 0x1a0) + 0x48), true)) {
        if (*(unsigned char*)(*(char**)(s + 0x1a0) + 0x4a) & 1) {
            ((grYakumono*)self)->setValid(0);
        }
    } else {
        if (!(*(unsigned char*)(*(char**)(s + 0x1a0) + 0x4a) & 1)) {
            ((grYakumono*)self)->setValid(0);
        }
    }
    if (g_stTriggerMng->getTriggerFlag(
            (stTriggerData*)(*(char**)(s + 0x1a0) + 0x44), false) == 1U) {
        ((grYakumono*)self)->setValid(0);
        *(int*)(s + 0x150) = 5;
    }
}
