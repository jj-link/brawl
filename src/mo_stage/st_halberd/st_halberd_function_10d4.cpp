#pragma force_active on

extern "C" {
extern char lbl_57_data_16C[];
extern char lbl_57_data_180[];
struct Ground;
Ground* fn_57_103CC(int, const char*, const char*);
void addGround__5StageFP6Ground(void*, Ground*);
}

struct Ground_base {
    char pad[0x3c];
};

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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_57_3A9C();
    virtual void slot37(void*, int, int);
    virtual void setNode();
    virtual void fn_57_638(void*);
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978();
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
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
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void slot67();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_57_3AC8();
    virtual void fn_57_3AC0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_57_3AB8();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_57_650(void*);
    virtual void fn_57_658(void*);
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120(void*);
    virtual void slot121(void*);
    virtual void slot122(int);
};

struct Elem {
    char pad[0x30];
};

struct Stage {
    char pad0[0x9c];
    void* f9c;
    char pad1[0x1a0 - 0xa0];
    void* f1a0;
    char pad2[0x4d8 - 0x1a4];
    Elem elems[1];
};

extern "C" void fn_57_10D4(Stage* stage, int index) {
    Ground* ground = fn_57_103CC(11, lbl_57_data_16C, lbl_57_data_180);
    if (ground != 0) {
        addGround__5StageFP6Ground(stage, ground);
        ground->slot37(stage->f1a0, 0, 0);
        ground->fn_57_638(stage->f9c);
        ground->slot120(&stage->elems[index]);
        ground->slot122(0);
        ground->fn_57_650((char*)stage + 0x1dc);
        ground->fn_57_658((char*)stage + 0x9b8);
        ground->slot121((char*)stage + 0x3d0);
    }
}
