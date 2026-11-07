#include <types.h>
#include <mt/mt_vector.h>
#include <so/collision/so_collision_attack_part.h>

#pragma force_active on

extern "C" void fn_27_2636F0(void*, int, int, soCollisionAttackData*);
extern "C" const float lbl_72_rodata_80[];

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
    virtual void fn_72_9F5C();
    virtual void fn_72_A04C();
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
    virtual void fn_72_1A98();
    virtual void startup();
    virtual void fn_72_A918();
    virtual void fn_72_468();
    virtual void fn_72_1A90();
    virtual void fn_72_1A8C();
    virtual void fn_72_1128();
    virtual void fn_72_1A84();
    virtual void fn_72_1A78();
    virtual void fn_72_1A68();
    virtual void fn_72_1A58();
    virtual void getNodeIndex();
    virtual bool getNodePosition(Vec3f* nodePos, u32 sceneModelIndex, u32 nodeIndex);
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
    virtual void fn_72_1A54();
    virtual void fn_72_1A50();
    virtual void fn_72_1A48();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_72_1A40();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_72_1AC4();
    virtual void fn_72_1ABC();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_72_1AB4();
    virtual void fn_72_BB5C();
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
    virtual void setAttackGimmickDetails(soCollisionAttackData* attackData, float size, float tripRate,
                                         float hitstopMultiplier, float sdiMultiplier, int power, Vec3f* offsetPos,
                                         int vector, int reactionEffect, int reactionFix, int reactionAdd,
                                         u32 nodeIndex, int collisionCategoryMask, int collisionSituationMask,
                                         bool unk1, int collisionPartMask, int attribute,
                                         int soundLevel, int soundAttr,
                                         bool isClankable, bool unk2, bool unk3, bool isShieldable, bool isReflectable,
                                         bool isAbsorbable, u32 addedShieldDamage, u32 detectionRate, bool unk5,
                                         bool ignoreInvincibility, bool ignoreIntangibility, int lrCheck,
                                         bool unk6, bool unk7, bool disableHitstop, bool disableHitGfx,
                                         bool disableFlinch, int region, bool isShapeCapsule);

public:
    char m_pad40[0x14c - 0x40];
    void* m_module;
    char m_pad150[0x16c - 0x150];
    u8 m_state16c;
    char m_pad16d[0x184 - 0x16d];
    u32 m_node184;
};

extern "C" void fn_72_B464(Ground* self, s32 arg1) {
    const float* k = lbl_72_rodata_80;
    Vec3f pos;
    u8 attackBuf[0x40];

    reinterpret_cast<soCollisionAttackData*>(attackBuf)->m_slipChance = k[19];
    reinterpret_cast<soCollisionAttackData*>(attackBuf)->m_region = soCollisionAttackData::Region_None;
    reinterpret_cast<soCollisionAttackData*>(attackBuf)->m_hitStopFrame = k[19];
    reinterpret_cast<soCollisionAttackData*>(attackBuf)->m_hitStopDelay = k[19];

    self->getNodePosition(&pos, 0, self->m_node184);

    switch (arg1) {
    case 0:
        pos.m_x = k[10];
        pos.m_y = k[11];
        pos.m_z = -pos.m_z;
        break;
    case 1:
        pos.m_x = k[0];
        pos.m_y = k[11];
        pos.m_z = -pos.m_z;
        break;
    case 2:
        pos.m_x = k[12];
        pos.m_y = k[11];
        pos.m_z = -pos.m_z;
        break;
    }

    switch (self->m_state16c) {
    case 0:
        if (arg1 == 0) {
            pos.m_y = k[13];
        } else if (arg1 == 1) {
            pos.m_y = k[14];
        } else if (arg1 == 2) {
            pos.m_y = k[13];
        }
        break;
    case 1:
        if (arg1 == 0) {
            pos.m_y = k[15];
        } else if (arg1 == 1) {
            pos.m_y = k[16];
        } else if (arg1 == 2) {
            pos.m_y = k[17];
        }
        break;
    case 2:
        if (arg1 == 0) {
            pos.m_y = k[17];
        } else if (arg1 == 1) {
            pos.m_y = k[16];
        } else if (arg1 == 2) {
            pos.m_y = k[15];
        }
        break;
    }

    self->setAttackGimmickDetails(reinterpret_cast<soCollisionAttackData*>(attackBuf), k[12], k[19], k[19], k[19], 0, &pos,
                                  90, 50, 100, 80,
                                  self->m_node184, 0x3ff, 7, false, 15, 0, 1, 0,
                                  false, false, false, false, false, false, 0, 60,
                                  false, false, false, 0, false, false, false, false, false, 0, true);

    fn_27_2636F0(self->m_module, arg1, 0, reinterpret_cast<soCollisionAttackData*>(attackBuf));
}
