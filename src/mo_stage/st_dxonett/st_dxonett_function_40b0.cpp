#pragma force_active on
#include <mt/mt_vector.h>

struct Constants { float x[16]; };
extern "C" const Constants lbl_78_rodata_A8;

struct Attack {
    char pad[36];
    Vec3f v;
    int a, b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.m_x = data->x[14];
        v.m_y = data->x[14];
        v.m_z = data->x[14];
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
    virtual void fn_78_38F4();
    virtual void fn_78_3978();
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
    virtual void fn_78_26A4();
    virtual void startup();
    virtual void setNode();
    virtual void fn_78_58C();
    virtual void fn_78_1C40();
    virtual void fn_78_26A0();
    virtual void fn_78_1760();
    virtual void fn_78_2698();
    virtual void fn_78_268C();
    virtual void fn_78_267C();
    virtual void fn_78_266C();
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
    virtual void fn_78_2668();
    virtual void fn_78_2664();
    virtual void fn_78_265C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_78_2654();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_78_26D0();
    virtual void fn_78_26C8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_78_26C0();
    virtual void onDamage();
    virtual void fn_78_4204();
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
        Attack*, int, Vec3f*, float, int, int, int, int,
        float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int);

    char pad40[0x14c - 0x40];
    void* module;
    char pad150[0x165 - 0x150];
    unsigned char done;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_78_40B0(Ground* self) {
    const Constants* data = &lbl_78_rodata_A8;

    if (self->done != 1) {
        Attack a(data);
        Vec3f p;
        p.m_x = data->x[0];
        p.m_y = data->x[0];
        p.m_z = data->x[0];

        self->setAttackGimmickDetails(
            &a, 0x1E, &p, data->x[8], 0x2D, 0x50, 0x96, 0,
            data->x[14], data->x[14], data->x[14],
            0, 0x3FF, 7, 0, 0xF, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0x3C,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        fn_27_2636F0(self->module, 0, 0, &a);
        self->done = 1;
    }
}
