#include <types.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct Constants { float x[23]; };
extern "C" const Constants lbl_57_rodata_300;
struct Attack {
 char pad[36]; Vec3f v; int a, b;
 unsigned upper:27; unsigned flags:5; int c;
 Attack(const Constants* data) {
  v.m_x = data->x[1]; v.m_y = data->x[1]; v.m_z = data->x[1]; flags = 0;
 }
};
extern "C" void fn_27_2636F0(void*, int, int, Attack*);

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
    virtual void fn_57_EDEC();
    virtual void fn_57_EE88();
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
    virtual void fn_57_3A9C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_57_638();
    virtual void fn_57_3A94();
    virtual void fn_57_3A90();
    virtual void fn_57_3978();
    virtual void fn_57_3A88();
    virtual void fn_57_3A7C();
    virtual void fn_57_3A6C();
    virtual void fn_57_3A5C();
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
    virtual void fn_57_3A58();
    virtual void fn_57_3A54();
    virtual void fn_57_3A4C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_57_3A44();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_57_3AC8();
    virtual void fn_57_3AC0();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_57_3AB8();
    virtual void onDamage();
    virtual void fn_57_10380();
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
    virtual void setAttackGimmickDetails(Attack* attackData, float size, float tripRate,
                                         float hitstopMultiplier, float sdiMultiplier, int power, Vec3f* offsetPos,
                                         int vector, int reactionEffect, int reactionFix, int reactionAdd,
                                         u32 nodeIndex, u32 categoryMask, u32 situationMask, bool unk1,
                                         u32 partMask, int attribute, int soundLevel, int soundAttr,
                                         bool isClankable, bool unk2, bool unk3, bool isShieldable,
                                         bool isReflectable, bool isAbsorbable, u32 addedShieldDamage,
                                         u32 detectionRate, bool unk5, bool ignoreInvincibility,
                                         bool ignoreIntangibility, int lrCheck, bool unk6, bool unk7,
                                         bool disableHitstop, bool disableHitGfx, bool disableFlinch,
                                         int region, bool isShapeCapsule);
};

extern "C" void fn_57_1002C(Ground* self, int arg1) {
    const Constants* data = &lbl_57_rodata_300;
    Attack attackData(data);
    const float* values = &data->x[1];
    Vec3f offsetPos(values[-1], values[-1], values[-1]);

    switch (arg1) {
    case 0:
        self->setAttackGimmickDetails(&attackData, data->x[22], data->x[1], data->x[1], data->x[1], 10, &offsetPos, 45, 60, 10, 78,
                                      *(u32*)((u8*)self + 0xc4), 0x3ff, 7, false, 0xf, 0, 2, 0, false, false,
                                      false, true, false, false, 0, 0xf, false, false, false, 0, false, false,
                                      false, false, false, 0, false);
        break;
    case 1:
        self->setAttackGimmickDetails(&attackData, data->x[11], data->x[1], data->x[1], data->x[1], 20, &offsetPos, 361, 50, 0, 78,
                                      *(u32*)((u8*)self + 0xc4), 0x3ff, 7, false, 0xf, 5, 2, 8, false, false,
                                      false, true, false, false, 0, 0x3c, false, false, false, 0, false, false,
                                      false, false, false, 0, false);
        break;
    }
    fn_27_2636F0(*(void**)((u8*)self + 0x14c), arg1, 0, &attackData);
}
