#include <st/stage.h>
#pragma force_active on

struct GroundViewBase { char pad[0x3c]; };
class GroundView : public GroundViewBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void slot6();
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
    virtual void slot35();
    virtual void fn_70_22A8();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_70_78C(void*);
    virtual void fn_70_22A0();
    virtual void fn_70_229C();
    virtual void fn_70_2080();
    virtual void fn_70_2294();
    virtual void fn_70_2288();
    virtual void fn_70_2278();
    virtual void fn_70_2268();
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
    virtual void fn_70_2264();
    virtual void fn_70_2260();
    virtual void fn_70_2258();
    virtual void slot65();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_70_2250();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_70_22D4();
    virtual void fn_70_22CC();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_70_22C4();
    virtual void slot90();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet10soAreaDataP10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_70_21B0();
    virtual void fn_70_794(void*);
    virtual void fn_70_79C();
    virtual void fn_70_7A4(void*);
};

extern "C" {
Ground* fn_70_6934(int, const char*, const char*);
extern const char lbl_70_data_648[];
extern const char lbl_70_data_660[];
}

extern "C" void fn_70_15CC(Stage* stage, int kind) {
    Ground* ground;
    switch (kind) {
    case 0xC:
        ground = fn_70_6934(0xA, lbl_70_data_648, lbl_70_data_660);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground != 0) {
        stage->addGround(ground);
        GroundView* view = (GroundView*)ground;
        view->startup(*(void**)((char*)stage + 0x1a0), 0, 0);
        view->fn_70_78C(*(void**)((char*)stage + 0x9c));
        view->fn_70_794((char*)stage + 0x1d8);
        view->fn_70_7A4((char*)stage + 0x1d9);
    }
}