#pragma force_active on
#include <mt/mt_vector.h>
struct Constants { float x[10]; };
extern "C" const Constants lbl_71_rodata_238;
struct Attack {
    char pad[36];
    Vec3f v;
    int a, b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;
    Attack(const Constants* data) {
        v.m_x = data->x[1];
        v.m_y = data->x[1];
        v.m_z = data->x[1];
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
    virtual void fn_71_E63C();
    virtual void fn_71_E6C0();
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
    virtual void startup();
    virtual void setNode();
    virtual void fn_71_85C();
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
    virtual void getMotionFrame();
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
    char pad150[0x176 - 0x150];
    unsigned char done;
};
extern "C" void fn_27_2636F0(void*, int, int, Attack*);
extern "C" void fn_71_EE08(Ground* self) {
    const Constants* data = &lbl_71_rodata_238;
    if (self->done != 1) {
        Attack a(data);
        Vec3f p;
        p.m_x = data->x[0];
        p.m_y = data->x[8];
        p.m_z = data->x[0];
        self->setAttackGimmickDetails(
            &a, 0, &p, data->x[9], 0x87, 0x37, 0x64, 0x46,
            data->x[1], data->x[1], data->x[1],
            0, 0x3ff, 7, 0, 15, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 60, 0, 1,
            1, 0, 0, 1, 1, 1, 1, 0, 1);
        fn_27_2636F0(self->module, 0, 0, &a);
        self->done = 1;
    }
}