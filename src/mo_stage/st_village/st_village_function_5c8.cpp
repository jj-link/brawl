#pragma force_active on
struct GroundBase {
    char pad[0x3c];
};

struct Ground : GroundBase {
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_70_21B0();
    virtual void fn_70_794(void*);
    virtual void fn_70_79C(unsigned char);
    virtual void fn_70_7A4(void*);
    virtual void fn_70_7AC(void*);
};

struct Stage {
    char pad0[0x9C];
    void* unk9C;
    char pad1[0x100];
    void* unk1A0;
    char pad2[0x34];
    char unk1D8[1];
    char unk1D9[7];
    char unk1E0[1];
};

extern "C" {
extern char lbl_70_data_0[];

Ground* fn_70_1F98(int, const char*, const char*);
Ground* fn_70_22DC(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_70_5C8(Stage* arg0, int arg1) {
    Ground* ground;
    const char* data = lbl_70_data_0;
    unsigned char flags = 0;

    switch (arg1) {
    case 0:
        ground = fn_70_1F98(0, data + 0x1C, data + 0x30);
        break;
    case 1:
        ground = fn_70_1F98(1, data + 0x40, data + 0x58);
        flags |= 0xC;
        break;
    case 2:
        ground = fn_70_22DC(2, data + 0x70, data + 0x84);
        break;
    case 3:
        ground = fn_70_1F98(3, data + 0x98, data + 0xB0);
        flags |= 0x1C;
        break;
    case 4:
        ground = fn_70_1F98(0xE, data + 0xC8, data + 0xE0);
        flags |= 0x18;
        break;
    case 5:
        ground = fn_70_1F98(0x11, data + 0xF0, data + 0x104);
        break;
    default:
        ground = 0;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(arg0, ground);
        ground->startup(arg0->unk1A0, 0, 0);
        ground->fn_70_78C(arg0->unk9C);
        ground->fn_70_794(arg0->unk1D8);
        ground->fn_70_79C(flags);
        ground->fn_70_7A4(arg0->unk1D9);
        ground->fn_70_7AC(arg0->unk1E0);
    }
}
}
