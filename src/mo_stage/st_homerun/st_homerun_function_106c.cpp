#pragma force_active on
struct GroundPrefix {
    char pad_0000[0x3c];
};

struct Ground : GroundPrefix {
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
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
    virtual void slot31();
    virtual void receiveCollMsg_Heading();
    virtual void slot33();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_88_447C();
    virtual void startup(void* data, int unk1, int layerType);
    virtual void slot38();
    virtual void fn_88_B1C(void* stageData);
    virtual void fn_88_4474();
    virtual void fn_88_4470();
    virtual void fn_88_4360();
    virtual void fn_88_4468();
    virtual void fn_88_445C();
    virtual void fn_88_444C();
    virtual void fn_88_443C();
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
    virtual void fn_88_4438();
    virtual void fn_88_4434();
    virtual void fn_88_442C();
    virtual void setMotionRatio();
    virtual void slot66();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_88_4424();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_88_44A8();
    virtual void fn_88_44A0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_88_4498();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117(void* p);
    virtual void slot118(void* p);
    virtual void slot119(int v);
};

struct Stage {
    char pad_0000[0x9c];
    void* field_009c;
    char pad_00a0[0x100];
    void* field_01a0;
};

extern "C" {
extern char lbl_88_data_0[];
Ground* fn_88_6C44(int, char*, char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_88_106C(Stage* stage, int kind) {
    Ground* ground;
    void* arg1;
    void* arg2;
    int arg3;
    char* data = lbl_88_data_0;

    switch (kind) {
    case 13:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x148);
        arg1 = (char*)stage + 0x440;
        arg2 = (char*)stage + 0x594;
        arg3 = 0x12;
        break;
    case 14:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x15c);
        arg1 = (char*)stage + 0x44c;
        arg2 = (char*)stage + 0x594;
        arg3 = 0x13;
        break;
    case 15:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x170);
        arg1 = (char*)stage + 0x458;
        arg2 = (char*)stage + 0x594;
        arg3 = 0x14;
        break;
    case 16:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x184);
        arg1 = (char*)stage + 0x464;
        arg2 = (char*)stage + 0x594;
        arg3 = 0x15;
        break;
    case 17:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x19c);
        arg1 = (char*)stage + 0x470;
        arg2 = (char*)stage + 0x598;
        arg3 = 0x12;
        break;
    case 18:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x1b0);
        arg1 = (char*)stage + 0x47c;
        arg2 = (char*)stage + 0x598;
        arg3 = 0x13;
        break;
    case 19:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x1c4);
        arg1 = (char*)stage + 0x488;
        arg2 = (char*)stage + 0x598;
        arg3 = 0x14;
        break;
    case 20:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x1d8);
        arg1 = (char*)stage + 0x494;
        arg2 = (char*)stage + 0x598;
        arg3 = 0x15;
        break;
    case 21:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x1f0);
        arg1 = (char*)stage + 0x4a0;
        arg2 = (char*)stage + 0x59c;
        arg3 = 0x12;
        break;
    case 22:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x204);
        arg1 = (char*)stage + 0x4ac;
        arg2 = (char*)stage + 0x59c;
        arg3 = 0x13;
        break;
    case 23:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x218);
        arg1 = (char*)stage + 0x4b8;
        arg2 = (char*)stage + 0x59c;
        arg3 = 0x14;
        break;
    case 24:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x22c);
        arg1 = (char*)stage + 0x4c4;
        arg2 = (char*)stage + 0x59c;
        arg3 = 0x15;
        break;
    case 25:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x244);
        arg1 = (char*)stage + 0x4d0;
        arg2 = (char*)stage + 0x5a0;
        arg3 = 0x12;
        break;
    case 26:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x258);
        arg1 = (char*)stage + 0x4dc;
        arg2 = (char*)stage + 0x5a0;
        arg3 = 0x13;
        break;
    case 27:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x26c);
        arg1 = (char*)stage + 0x4e8;
        arg2 = (char*)stage + 0x5a0;
        arg3 = 0x14;
        break;
    case 28:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x280);
        arg1 = (char*)stage + 0x4f4;
        arg2 = (char*)stage + 0x5a0;
        arg3 = 0x15;
        break;
    case 29:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x298);
        arg1 = (char*)stage + 0x500;
        arg2 = (char*)stage + 0x5a4;
        arg3 = 0x12;
        break;
    case 30:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x2ac);
        arg1 = (char*)stage + 0x50c;
        arg2 = (char*)stage + 0x5a4;
        arg3 = 0x13;
        break;
    case 31:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x2c0);
        arg1 = (char*)stage + 0x518;
        arg2 = (char*)stage + 0x5a4;
        arg3 = 0x14;
        break;
    case 32:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x2d4);
        arg1 = (char*)stage + 0x524;
        arg2 = (char*)stage + 0x5a4;
        arg3 = 0x15;
        break;
    case 33:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x2ec);
        arg1 = (char*)stage + 0x530;
        arg2 = (char*)stage + 0x5a8;
        arg3 = 0x12;
        break;
    case 34:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x300);
        arg1 = (char*)stage + 0x53c;
        arg2 = (char*)stage + 0x5a8;
        arg3 = 0x13;
        break;
    case 35:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x314);
        arg1 = (char*)stage + 0x548;
        arg2 = (char*)stage + 0x5a8;
        arg3 = 0x14;
        break;
    case 36:
        ground = fn_88_6C44(0x28, data + 0x140, data + 0x328);
        arg1 = (char*)stage + 0x554;
        arg2 = (char*)stage + 0x5a8;
        arg3 = 0x15;
        break;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->field_01a0, 0x40, 0);
        ground->fn_88_B1C(stage->field_009c);
        ground->slot117(arg1);
        ground->slot118(arg2);
        ground->slot119(arg3);
    }
}
}
