#pragma force_active on
#include <types.h>
#include <ec/ec_mgr.h>
#include <gm/gm_global.h>
#include <gm/gm_stage_data.h>

struct Ground_base {
    unsigned char pad[0x3C];
};

class GroundObj : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void fn_27_260174();
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
    virtual void fn_27_260920();
    virtual void init();
    virtual void fn_27_25F4B0();
    virtual void fn_27_260228(gmStageData* stageData, float scale);
    virtual void loadGroundData();
    virtual void fn_27_25F524();
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
    virtual void fn_27_260B40();
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
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void setInitializeFlag();
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void fn_27_261EA0();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void fn_27_260224();

    unsigned char pad40[0x2D];
    unsigned char flags6D;
};

struct BssHolder {
    unsigned char pad[0xAC];
    unsigned char flagAC;
};

extern "C" float lbl_27_data_547E0;
extern "C" BssHolder* lbl_27_bss_5668;

extern "C" void fn_27_260174(GroundObj* self) {
    g_ecMgr->pushsetCurrentGroup(0x02000000);
    if (!((self->flags6D >> 4) & 1)) {
        gmStageData* stageData = g_GameGlobal->m_stageData;
        float t = lbl_27_data_547E0 * stageData->m_motionRatio;
        t *= stageData->m_motionSubRatio;
        self->fn_27_260228(stageData, t);
    }
    g_ecMgr->popCurrentGroup();
    if (lbl_27_bss_5668->flagAC) {
        self->fn_27_260224();
    }
}