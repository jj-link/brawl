#pragma force_active on

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

struct Rodata {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
};

extern "C" const Rodata lbl_68_rodata_1D8;

struct Ground_base { char pad[0x3c]; };

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
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
    virtual void fn_68_11A00();
    virtual void fn_68_11A90();
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
    virtual void fn_68_249C();
    virtual void startup();
    virtual void fn_68_120B4();
    virtual void fn_68_97C();
    virtual void fn_68_2494();
    virtual void fn_68_2490();
    virtual void fn_68_2390();
    virtual void fn_68_2488();
    virtual void fn_68_247C();
    virtual void fn_68_246C();
    virtual void fn_68_B50();
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
    virtual void fn_68_2468();
    virtual void fn_68_2464();
    virtual void fn_68_245C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_68_2454();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_68_24C8();
    virtual void fn_68_24C0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_68_24B8();
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
    virtual void setAttackGimmickDetails(Attack* a, float f1, float f2, float f3, float f4,
        int i1, Vec* p, int i2, int i3, int i4, int i5,
        unsigned u1, unsigned u2, unsigned u3, bool b1, unsigned u4,
        int e1, int e2, int e3,
        bool b2, bool b3, bool b4, bool b5, bool b6, bool b7,
        unsigned u5, unsigned u6,
        bool b8, bool b9, bool b10,
        int lr, bool b11, bool b12, bool b13, bool b14, bool b15,
        int region, bool b16);

    char p[0x14c - 0x40];
    void* module;
    char r[0x179 - 0x150];
    unsigned char state;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_68_124A4(Ground* self) {
    const Rodata* d = &lbl_68_rodata_1D8;
    if (self->state != 1) {
        Attack a;
        Vec p;
        a.v.x = d->f1c;
        a.v.y = d->f1c;
        a.v.z = d->f1c;
        a.flags = 0;
        p.x = d->f0;
        p.y = d->f0;
        p.z = d->f0;
        self->setAttackGimmickDetails(&a, d->f20, d->f1c, d->f1c, d->f1c,
            0x14, &p, 0x1e, 0x32, 0, 0x46,
            0, 0x2f7, 7, false, 0xf,
            5, 2, 8,
            false, false, false, true, false, false,
            0, 0x5a,
            false, false, false,
            0, false, false, false, false, false,
            0, true);
        fn_27_2636F0(self->module, 0, 0, &a);
        self->state = 1;
    }
}
