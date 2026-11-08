#include <st/stage.h>
#pragma force_active on
struct GroundVirtualBase { char pad[0x3c]; };
class GroundVirtual : public GroundVirtualBase {
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
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_78_26A4();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_78_58C(void*);
    virtual void fn_78_1C40();
    virtual void fn_78_26A0();
    virtual void fn_78_1760();
    virtual void fn_78_2698();
    virtual void fn_78_268C();
    virtual void fn_78_267C();
    virtual void fn_78_266C();
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
    virtual void fn_78_2668();
    virtual void fn_78_2664();
    virtual void fn_78_265C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_78_2654();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_78_26D0();
    virtual void fn_78_26C8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_78_26C0();
    virtual void onDamage();
    virtual void slot91();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_78_670();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116(void*);
    virtual void slot117(void*);
    virtual void slot118(void*);
    virtual void slot119(int);
};
extern "C" {
extern char lbl_78_data_0[];
Ground* fn_78_7B50(int, const char*, const char*);
void fn_78_680(Stage* stage, int kind) {
    char* data = lbl_78_data_0;
    char* self = (char*)stage;
    Ground* ground;
    switch (kind) {
    case 2:
        ground = fn_78_7B50(2, data + 0x40, data + 0x58);
        break;
    case 3:
        ground = fn_78_7B50(9, data + 0x68, data + 0x7c);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        GroundVirtual* g = (GroundVirtual*)ground;
        g->startup(*(void**)(self + 0x1a0), 0, 0);
        g->fn_78_58C(*(void**)(self + 0x9c));
        g->slot116(self + 0x2ec);
        g->slot117(self + 0x2ed);
        g->slot118(self + 0x2ee);
        switch (kind) {
        case 3:
            g->slot119(1);
            break;
        }
    }
}
}
