#pragma force_active on

typedef unsigned char u8;

struct Vec {
    float x, y, z;
};

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;
};

extern "C" const float lbl_52_rodata_E8[];

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_52_4E70();
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
    virtual void fn_52_4DE0();
    virtual void fn_52_4F0C();
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
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8();
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
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
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_52_3694();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_52_3718();
    virtual void fn_52_3710();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_52_3708();
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
    virtual void setAttackGimmickDetails(Attack*, int, Vec*, int, int, int, int, float, float, float, float,
        int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);

    char p[0x14c - 0x40];
    void* module;
    char q[0x185 - 0x150];
    unsigned char state;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_52_5E94(Ground* self) {
    const float* d = lbl_52_rodata_E8;
    if (self->state != 1) {
        Vec p;
        Attack a;
        a.v.x = d[0x44 / 4];
        a.v.y = d[0x44 / 4];
        a.flags = 0;
        a.v.z = d[0x44 / 4];
        p.x = d[0x4c / 4];
        p.y = d[0x50 / 4];
        p.z = d[0];
        self->setAttackGimmickDetails(&a, 0x14, &p, 0x10e, 0xc8, 0xc8, 0x64,
            d[0x54 / 4], d[0x44 / 4], d[0x44 / 4], d[0x44 / 4],
            2, 0x3ff, 7, 0, 0xf, 0, 2, 1, 0, 0, 0, 1, 0, 0, 0, 0x3c,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
        fn_27_2636F0(self->module, 0, 0, &a);
        self->state = 1;
    }
}
