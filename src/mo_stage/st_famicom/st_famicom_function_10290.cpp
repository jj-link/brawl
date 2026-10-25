#pragma force_active on
#include <mt/mt_vector.h>

struct Constants {
    float x[5];
};

extern "C" const Constants lbl_68_rodata_198;

struct Attack {
    char pad[36];
    Vec3f v;
    int a, b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.m_x = data->x[0];
        v.m_y = data->x[0];
        v.m_z = data->x[0];
        flags = 0;
    }
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_68_A240();
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
    virtual void fn_68_100BC();
    virtual void fn_68_A290();
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
    virtual void setNode();
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
    virtual void fn_68_C5BC();
    virtual void fn_68_C6C4();
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
    virtual void setAttackGimmickDetails(
        Attack*, int, Vec3f*, int, int, int, int,
        float, float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int
    );

    char pad40[0x14c - 0x40];
    void* module;
    char pad150[0x174 - 0x150];
    unsigned char kind;
    char pad175[0x189 - 0x175];
    unsigned char done;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_68_10290(Ground* self) {
    const Constants* data = &lbl_68_rodata_198;

    if (self->done != 1) {
        Attack a(data);
        Vec3f p;
        int kind;

        p.m_x = data->x[1];
        p.m_y = data->x[1];
        p.m_z = data->x[1];

        switch (self->kind) {
        case 1:
            kind = 0xD;
            break;
        case 2:
            kind = 0xF;
            break;
        case 3:
            kind = 0x11;
            break;
        default:
            kind = 0;
            break;
        }

        self->setAttackGimmickDetails(
            &a, kind, &p, 0, 100, 0, 30,
            data->x[4], data->x[0], data->x[0], data->x[0],
            0, 0x2F7, 7, 0, 0xF, 2, 2, 3, 0,
            0, 0, 1, 0, 0, 0xA, 0x78, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 2, 0
        );

        fn_27_2636F0(self->module, 0, 0, &a);
        self->done = 1;
    }
}
