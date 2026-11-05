#pragma force_active on
#include <st/stage.h>

namespace Matching {
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
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
    virtual void slot14();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
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
    virtual void fn_63_3378();
    virtual void slot37(gfArchive*, u32, u32);
    virtual void slot38();
    virtual void fn_63_59C(void*);
    virtual void fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
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
    virtual void slot62();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
    virtual void slot90();
    virtual void slot91();
    virtual void onInflictEach();
    virtual void slot93();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void slot100();
    virtual void slot101();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115(void*);
    virtual void slot116(u32);
    virtual void slot117();
    virtual void slot118(Vec3f*);
    virtual void slot119(void*);
    virtual void slot120(void*);
    virtual void slot121(void*);
    virtual void slot122(u32);
};
}

struct GameWatchStage : Stage {
    gfArchive* resource;
    char pad1a4[0x3c];
    u32 field1e0;
    char field1e4[0x30];
    Vec3f positions[20];
    char field304[0x158];
    void* field45c;
};

extern "C" {
extern char lbl_63_data_1F0[];
extern char lbl_63_data_1FC[];
Matching::Ground* fn_63_5DAC(int, const char*, const char*);

void fn_63_E60(GameWatchStage* stage) {
    Vec3f* position = stage->positions;
    Matching::Ground* ground;
    u32 index = 0;
loop:
    {
        ground = fn_63_5DAC(0x25, lbl_63_data_1F0, lbl_63_data_1FC);
        if (!ground)
            return;
        stage->addGround((::Ground*)ground);
        ground->slot37(stage->resource, 0, 0);
        ground->fn_63_59C(stage->m_stageData);
        ground->slot115(&stage->field1e0);
        ground->slot116(0);
        ground->slot118(position);
        ground->slot119(stage->field304);
        ground->slot121(stage->field45c);
        ground->slot122(index);
        ground->slot120(stage->field1e4);
        ++index;
        ++position;
    }
    if (index != 20)
        goto loop;
}
}
