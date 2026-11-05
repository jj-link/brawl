#pragma force_active on

class Ground_base {
public:
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
    virtual void slot32();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_48_203C();
    virtual void startup(void* archive, int a, int b);
    virtual void setNode();
    virtual void fn_48_7BC(void* value);
    virtual void fn_48_2034();
    virtual void fn_48_2030();
    virtual void fn_48_1F20();
    virtual void fn_48_2028();
    virtual void fn_48_201C();
    virtual void fn_48_200C();
    virtual void fn_48_1FFC();
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
    virtual void fn_48_1FF8();
    virtual void fn_48_1FF4();
    virtual void fn_48_1FEC();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_48_1FE4();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_48_2068();
    virtual void fn_48_2060();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_48_2058();
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
    virtual void slot112(void* p);
    virtual void slot113(void* p);
    virtual void slot114(unsigned char v);
};

struct Stage {
    char pad0[0x9c];
    void* unk9C;
    char padA0[0x1a0 - 0xa0];
    void* unk1A0;
    char pad1A4[0x1e4 - 0x1a4];
    char unk1E4[0x210 - 0x1e4];
    char unk210[0x2c4 - 0x210];
    unsigned char unk2C4;
};

extern "C" {
extern char lbl_48_data_0[];
Ground* fn_48_29C0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_48_68C(Stage* arg0, int arg1) {
    Ground* var_r31 = 0;
    const char* data = lbl_48_data_0;

    switch (arg0->unk2C4) {
    case 0:
        switch (arg1) {
        case 0:
            var_r31 = fn_48_29C0(2, data + 0x4c, data + 0x6c);
            break;
        default:
            break;
        }
        break;
    case 1:
        switch (arg1) {
        case 0:
            var_r31 = fn_48_29C0(2, data + 0x84, data + 0x6c);
            break;
        default:
            break;
        }
        break;
    }

    if (var_r31 != 0) {
        addGround__5StageFP6Ground(arg0, var_r31);
        var_r31->startup(arg0->unk1A0, 0, 0);
        var_r31->fn_48_7BC(arg0->unk9C);
        var_r31->slot114(arg0->unk2C4);
        var_r31->slot112(arg0->unk1E4);
        var_r31->slot113(arg0->unk210);
    }
}
}
