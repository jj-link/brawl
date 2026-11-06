#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

// vtable at 0xa28 and more; object holds vtable pointer at offset 0x3c
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();  // 0x8
    virtual void processBegin();  // 0xc
    virtual void slot2();  // 0x10
    virtual void processUpdate();  // 0x14
    virtual void processPreMapCorrection();  // 0x18
    virtual void processMapCorrection();  // 0x1c
    virtual void processFixPosition();  // 0x20
    virtual void processPreCollision();  // 0x24
    virtual void processCollision();  // 0x28
    virtual void processCatch();  // 0x2c
    virtual void processHit();  // 0x30
    virtual void processCamera();  // 0x34
    virtual void processFixCamera();  // 0x38
    virtual void processEffect();  // 0x3c
    virtual void processGameProc();  // 0x40
    virtual void processEnd();  // 0x44
    virtual void renderPre();  // 0x48
    virtual void renderOpa();  // 0x4c
    virtual void renderXlu();  // 0x50
    virtual void processDebug();  // 0x54
    virtual void renderDebug();  // 0x58
    virtual void init();  // 0x5c
    virtual void slot22();  // 0x60
    virtual void slot23();  // 0x64
    virtual void loadGroundData();  // 0x68
    virtual void bindData();  // 0x6c
    virtual void setupMelee();  // 0x70
    virtual void setVisibility();  // 0x74
    virtual void setVisibilityByClipping();  // 0x78
    virtual void setVisibilityAttachedEffect();  // 0x7c
    virtual void receiveCollMsg();  // 0x80
    virtual void slot31();  // 0x84
    virtual void receiveCollMsg_Heading();  // 0x88
    virtual void receiveCollMsg_Wall();  // 0x8c
    virtual void receiveCollMsg_Attack();  // 0x90
    virtual void unloadData();  // 0x94
    virtual void getModelCount();  // 0x98
    virtual void startup(void*, int, int);  // 0x9c
    virtual void slot38();  // 0xa0
    virtual void setStageData(void*);  // 0xa4
    virtual void getStageData();  // 0xa8
    virtual void initStageData();  // 0xac
    virtual void setMdlIndex(int);  // 0xb0
    virtual void getMdlIndex();  // 0xb4
    virtual void isEnableCalcCollision();  // 0xb8
    virtual void enableCalcCollision();  // 0xbc
    virtual void disableCalcCollision();  // 0xc0
    virtual void getNodeIndex();  // 0xc4
    virtual void getNodePosition();  // 0xc8
    virtual void getNodePosition_2();  // 0xcc
    virtual void getNodeMatrix();  // 0xd0
    virtual void getNodeMatrix_2();  // 0xd4
    virtual void setNodeVisibility();  // 0xd8
    virtual void setNodeVisibility_2();  // 0xdc
    virtual void setNodeVisibilityAll();  // 0xe0
    virtual void isNodeVisible();  // 0xe4
    virtual void setNodeCollision();  // 0xe8
    virtual void setNodeCollision_2();  // 0xec
    virtual void getNodeScale();  // 0xf0
    virtual void getNodeScale_2();  // 0xf4
    virtual void setValid();  // 0xf8
    virtual void setValidAttachedEffect();  // 0xfc
    virtual void setInitializeFlag();  // 0x100
    virtual void setInitializeInfo(int);  // 0x104
    virtual void getInitializeInfo();  // 0x108
    virtual void setMotionRatio();  // 0x10c
    virtual void setMotionFrame();  // 0x110
    virtual void getMotionFrame();  // 0x114
    virtual void setMotionLoop();  // 0x118
    virtual void setMatAlphaMul();  // 0x11c
    virtual void setMatAlpha();  // 0x120
    virtual void updateG3dProcCalcWorld();  // 0x124
    virtual void preExit();  // 0x128
    virtual void adventureEventGetItem();  // 0x12c
    virtual void invalidatedByCameraClipping();  // 0x130
    virtual void setTransparencyFlag();  // 0x134
    virtual void updateCallback();  // 0x138
    virtual void fixedPosition();  // 0x13c
    virtual void setTgtNode(const char*);  // 0x140
    virtual void getTgtNode();  // 0x144
    virtual void setGimmickData();  // 0x148
    virtual void getGimmickData();  // 0x14c
    virtual void changeNodeAnim();  // 0x150
    virtual void createFadeVisibleProduction();  // 0x154
    virtual void createSoundEffectVisibleProductionForExcel();  // 0x158
    virtual void createEffectVisibleProductionForExcel();  // 0x15c
    virtual void setSimpleEffectVisibleProduction();  // 0x160
    virtual void dbDispInvalidatedByCameraClippingSphere();  // 0x164
    virtual void setTransparency();  // 0x168
    virtual void getTransparencyFlag();  // 0x16c
    virtual void onDamage();  // 0x170
    virtual void onInflict();  // 0x174
    virtual void onInflictEach();  // 0x178
    virtual void onGimmickEvent();  // 0x17c
    virtual void enableYakumono();  // 0x180
    virtual void disableYakumono();  // 0x184
    virtual void enableHit();  // 0x188
    virtual void disableHit();  // 0x18c
    virtual void disableAttack();  // 0x190
    virtual void enableArea();  // 0x194
    virtual void disableArea();  // 0x198
    virtual void setSleepArea();  // 0x19c
    virtual void setTeamYakumonoOwnerId();  // 0x1a0
    virtual void setTeamYakumono();  // 0x1a4
    virtual void getTeamYakumono();  // 0x1a8
    virtual void setOffsetAttack();  // 0x1ac
    virtual void setAreaGimmick();  // 0x1b0
    virtual void setAttackGimmick();  // 0x1b4
    virtual void setSoCollisionAttackData();  // 0x1b8
    virtual void setAttackGimmickDetails();  // 0x1bc
    virtual void isEnableAttackPersonAttacked();  // 0x1c0
    virtual void isEnableAttackAttribute();  // 0x1c4
    virtual void slot112();  // 0x1c8
    virtual void fn_81_505C(void*);  // 0x1cc
    virtual void fn_81_AA4(void*);  // 0x1d0
    virtual void fn_81_AB4(void*);  // 0x1d4
};

struct Stage {
    char pad0[0x9c];
    void* value;
    char padA0[0x1a0 - 0xa0];
    void* archive;
    char pad1A4[0x1e0 - 0x1a4];
    u8 unk1E0[0x1fc - 0x1e0];
    u8 unk1FC[0x208 - 0x1fc];
    u8 unk208[0x20c - 0x208];
};

extern "C" {
extern char lbl_81_data_0[];
Ground* fn_81_42C8(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_81_984(Stage* stage, int kind) {
    Ground* ground;
    char* data = lbl_81_data_0;

    switch (kind) {
    case 0:
        ground = fn_81_42C8(1, data + 0x10, data + 0x20);
        break;
    case 1:
        ground = fn_81_42C8(2, data + 0x30, data + 0x40);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->startup(stage->archive, 0, 0);
        ground->setStageData(stage->value);
        ground->fn_81_505C(&stage->unk1FC);
        ground->fn_81_AA4(&stage->unk1E0);
        ground->fn_81_AB4(&stage->unk208);
    }
}
}
