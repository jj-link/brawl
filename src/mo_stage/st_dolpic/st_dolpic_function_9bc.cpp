#include <st/stage.h>
#pragma force_active on

struct GroundBase { char pad[0x3c]; };
class DolpicGround : public GroundBase {
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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_46_4860();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_46_8D0(void*);
    virtual void fn_46_4858();
    virtual void fn_46_4854();
    virtual void fn_46_44AC();
    virtual void fn_46_484C();
    virtual void fn_46_4840();
    virtual void fn_46_4830();
    virtual void fn_46_4820();
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
    virtual void fn_46_481C();
    virtual void fn_46_4818();
    virtual void fn_46_4810();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void slot67();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_46_4808();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_46_488C();
    virtual void fn_46_4884();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_46_487C();
    virtual void onDamage();
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
    virtual void fn_46_4630();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116(void*);
    virtual void slot117(void*);
    virtual void slot118(int);
};
extern "C" {
extern char lbl_46_data_0[];
DolpicGround* fn_46_56F0(int, const char*, const char*);
void fn_46_9BC(Stage* stage, unsigned int kind) {
    DolpicGround* ground;
    char* ptr;
    int index;
    char* data = lbl_46_data_0;
    switch (kind) {
    case 2:
        ground = fn_46_56F0(1, data + 0x54, data + 0x6c);
        ptr = (char*)stage + 0x1f5;
        index = 2;
        break;
    case 3:
        ground = fn_46_56F0(12, data + 0x7c, data + 0x98);
        ptr = (char*)stage + 0x1f6;
        index = 3;
        break;
    case 4:
        ground = fn_46_56F0(13, data + 0xac, data + 0xc8);
        ptr = (char*)stage + 0x1f6;
        index = 4;
        break;
    case 5:
        ground = fn_46_56F0(22, data + 0xdc, data + 0xf8);
        ptr = (char*)stage + 0x1f7;
        index = 5;
        break;
    case 6:
        ground = fn_46_56F0(23, data + 0x10c, data + 0x128);
        ptr = (char*)stage + 0x1f7;
        index = 6;
        break;
    case 7:
        ground = fn_46_56F0(32, data + 0x13c, data + 0x158);
        ptr = (char*)stage + 0x1f8;
        index = 7;
        break;
    case 8:
        ground = fn_46_56F0(33, data + 0x16c, data + 0x188);
        ptr = (char*)stage + 0x1f8;
        index = 8;
        break;
    case 9:
        ground = fn_46_56F0(34, data + 0x19c, data + 0x1b8);
        ptr = (char*)stage + 0x1f8;
        index = 9;
        break;
    case 10:
        ground = fn_46_56F0(42, data + 0x1cc, data + 0x1e8);
        ptr = (char*)stage + 0x1f9;
        index = 10;
        break;
    case 11:
        ground = fn_46_56F0(43, data + 0x1fc, data + 0x218);
        ptr = (char*)stage + 0x1f9;
        index = 11;
        break;
    case 12:
        ground = fn_46_56F0(44, data + 0x22c, data + 0x248);
        ptr = (char*)stage + 0x1f9;
        index = 12;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround((Ground*)ground);
        ground->startup(*(void**)((char*)stage + 0x1a0), 0, 0);
        ground->fn_46_8D0(*(void**)((char*)stage + 0x9c));
        ground->slot116((char*)stage + 0x1e4);
        ground->slot117(ptr);
        ground->slot118(index);
        *((char*)stage + 0x1f5) = 1;
        *((char*)stage + 0x1f6) = 1;
    }
}
}