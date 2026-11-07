#pragma force_active on
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
    virtual void fn_62_3114();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_62_A44(void*);
    virtual void fn_62_310C();
    virtual void fn_62_3108();
    virtual void fn_62_2C7C();
    virtual void fn_62_3100();
    virtual void fn_62_30F4();
    virtual void fn_62_30E4();
    virtual void fn_62_30D4();
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
    virtual void fn_62_30D0();
    virtual void fn_62_30CC();
    virtual void fn_62_30C4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_62_30BC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_62_3140();
    virtual void fn_62_3138();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_62_3130();
    virtual void slot90();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void slot93();
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
    virtual void slot112();
    virtual void slot113();
    virtual void slot114(void*);
    virtual void slot115(void*);
    virtual void slot116(void*);
};
class Stage {
public:
    char pad0[0x9c];
    void* f9c;
    char padA0[0x100];
    void* f1a0;
    void addGround(Ground*);
};
extern "C" {
extern char lbl_62_data_0[];
Ground* fn_62_CDCC(int, const char*, const char*);
void fn_62_D28(Stage* stage, int kind) {
    Ground* ground;
    char* ptr1;
    char* ptr2;
    char* data = lbl_62_data_0;
    switch (kind) {
    case 4:
        ground = fn_62_CDCC(4, data + 0xb8, data + 0xc4);
        ptr1 = (char*)stage + 0x1e0;
        ptr2 = (char*)stage + 0x4bc;
        break;
    case 5:
        ground = fn_62_CDCC(5, data + 0xd4, data + 0xe0);
        ptr1 = (char*)stage + 0x240;
        ptr2 = (char*)stage + 0x4bd;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        ground->startup(stage->f1a0, 0, 0);
        ground->fn_62_A44(stage->f9c);
        ground->slot114(ptr1);
        ground->slot115((char*)stage + 0x420);
        ground->slot116(ptr2);
    }
}
}