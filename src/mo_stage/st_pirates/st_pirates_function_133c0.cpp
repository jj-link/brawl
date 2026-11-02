#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Constants {
    float x[21];
};

extern "C" const Constants lbl_52_rodata_328;

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.x = data->x[5];
        v.y = data->x[5];
        v.z = data->x[5];
        flags = 0;
    }
};

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
    virtual void fn_52_132AC();
    virtual void fn_52_12798();
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
    virtual void disableAttack(unsigned int);
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
    virtual void setAttackGimmickDetails(
        Attack*, int, Vec*, float, int, int, int, int,
        float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int
    );

    char q[0xc4 - 0x40];
    int id;
    char r[0x14c - 0xc8];
    void* module;
    char s[0x164 - 0x150];
    unsigned char* kind;
    char t[0x199 - 0x168];
    unsigned char prevKind;
    char u;
    unsigned char done;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_52_133C0(Ground* o) {
    const Constants* data = &lbl_52_rodata_328;
    if (o->module != 0) {
        Attack a(data);
        if (o->done == 1) {
            if (*o->kind == o->prevKind) {
                return;
            }
            o->disableAttack(0);
            o->done = 0;
        }
        float size;
        unsigned char k = *o->kind;
        if (k == 0) {
            size = data->x[18];
        } else if (k == 1) {
            size = data->x[20];
        }

        Vec p;
        p.x = data->x[7];
        p.y = data->x[7];
        p.z = data->x[7];

        o->setAttackGimmickDetails(
            &a, 10, &p, size, 70, 100, 70, 0,
            data->x[5], data->x[5], data->x[5],
            o->id, 1023, 7, 0, 15, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 30, 0, 1,
            1, 3, 0, 1, 1, 1, 0, 0, 0
        );

        fn_27_2636F0(o->module, 0, 0, &a);
        o->done = 1;
    }
}
