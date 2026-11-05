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
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_71_2B8C();
    virtual void startup(void*, int, int);
    virtual void slot38();
    virtual void fn_71_85C(void*);
    virtual void fn_71_2B84();
    virtual void fn_71_2B80();
    virtual void fn_71_2700();
    virtual void fn_71_2B78();
    virtual void fn_71_2B6C();
    virtual void fn_71_2B5C();
    virtual void fn_71_F04();
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
    virtual void fn_71_2B58();
    virtual void fn_71_2B54();
    virtual void fn_71_2B4C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void slot67();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_71_2B44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_71_2BB8();
    virtual void fn_71_2BB0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_71_2BA8();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115(void*);
    virtual void slot116(void*);
    virtual void slot117(unsigned char);
    virtual void slot118(int);
};

struct Stage {
    char pad0[0x9c];
    void* scene;
    char pad1[0x100];
    void* archive;
    char pad2[0x3c];
    char info[0xc4];
    unsigned char kind;
    char state;
};

extern "C" {
extern char lbl_71_data_0[];
Ground* fn_71_32A8(int, const char*, const char*);
Ground* fn_71_4B0C(int, const char*, const char*);
Ground* fn_71_537C(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_71_FD4(Stage* stage, int kind) {
    Ground* other;
    Ground* ground;
    char* data = lbl_71_data_0;
    switch (kind) {
    case 13:
        ground = fn_71_32A8(0x14, data + 0x224, data + 0x23c);
        other = fn_71_32A8(0x14, data + 0x224, data + 0x250);
        stage->kind = 0;
        break;
    case 14:
        ground = fn_71_4B0C(0x14, data + 0x264, data + 0x27c);
        stage->kind = 1;
        other = 0;
        break;
    case 15:
        ground = fn_71_537C(0x14, data + 0x28c, data + 0x2a4);
        stage->kind = 2;
        other = 0;
        break;
    default:
        ground = 0;
        other = 0;
        break;
    }
    if (ground || other) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->archive, 0, 0);
        ground->fn_71_85C(stage->scene);
        ground->slot115(stage->info);
        ground->slot116(&stage->state);
        ground->slot117(stage->kind);
        ground->slot118(0);
        if (other) {
            addGround__5StageFP6Ground(stage, other);
            other->startup(stage->archive, 0, 0);
            other->fn_71_85C(stage->scene);
            other->slot115(stage->info);
            other->slot116(&stage->state);
            other->slot117(stage->kind);
            other->slot118(1);
        }
    }
}
}
