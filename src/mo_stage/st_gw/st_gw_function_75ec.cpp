#include <ai/ai_mgr.h>
#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" const float lbl_63_rodata_A8[];
extern "C" float randf__Fv();
extern "C" void fn_27_1F299C(aiMgr* mgr, int id);

struct StGwGroundParam {
    char _00[0x7C];
    float m7C;
    float m80;
    float m84;
    float m88;
};

struct PanelZone {
    Vec2f lo, hi;
    Vec3f position;
} __attribute__((aligned(8)));

static inline void setCorner(Vec2f& p, float x, float y) {
    p.m_x = x;
    p.m_y = y;
}

struct StGwGroundNode {
    float timer;
    u32 unk4;
    u8 counter;
    u8 state;
    u8 unkA;
    u8 unkB;
};

struct StGwGroundBase {
    char pad[0x3c];
};

class StGwGround : public StGwGroundBase {
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
    virtual void fn_63_65C8();
    virtual void fn_63_66AC();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual StGwGroundParam* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual bool getNodePosition(Vec3f* pos, u32 sceneModelIndex, u32 nodeIndex);
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual bool setNodeVisibility(bool setVisibility, u32 sceneModelIndex, u32 nodeIndex, bool recursive, bool recursive_);
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_63_3334();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
    virtual void fn_63_8CE4();
    virtual void fn_63_8C60();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack(u32 idx);
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
    virtual void fn_63_2D00();
    virtual void fn_63_7C78();
    virtual void fn_63_2ED8();
    virtual void fn_63_C50();
    virtual void fn_63_C58();
    virtual void fn_63_6750();
    virtual void fn_63_6BF8();
    virtual void fn_63_72C0();
    virtual void fn_63_75EC();
    virtual void fn_63_7DE4();
    virtual void fn_63_8808(u32 idx);
    virtual void fn_63_86B4();
    virtual void fn_63_8968();
    virtual u32 fn_63_8BD0(u32 idx);

    inline void updatePanels(float deltaFrame);

    char _40[0x180 - 0x40];
    int m_nodeId[20];
    char _1D0[0x204 - 0x1D0];
    StGwGroundNode m_node[4];
    char _234[0x27C - 0x234];
    u8 m27C;
    char _27D[0x294 - 0x27D];
    int m_dz[4];
};

static inline void disableNode(StGwGround* self, StGwGroundNode* node, u8 idx) {
    self->disableAttack(idx);
    node->unkB = 0;
}

static inline void setZone(StGwGround* self, StGwGroundNode* node, u8 idx, float f31) {
                        Vec3f pos;
                        self->getNodePosition(&pos, 0, self->m_nodeId[node->counter + idx * 5]);
                        Vec2f lo(pos.m_x - f31, f31 + pos.m_y);
                        Vec2f hi(f31 + pos.m_x, pos.m_y - f31);
                        self->m_dz[idx] = g_aiMgr->setDangerZone(&lo, &hi, self->m_dz[idx], false, false);
}

extern "C" void fn_63_75EC(StGwGround* self, float deltaFrame) {
    u8 idx;
    const float* const k = lbl_63_rodata_A8;
    StGwGroundParam* param = self->fn_63_3370();
    if (param != NULL) {
        float f31 = k[7];
        float f30 = k[0];

        idx = 0;
        while (idx < 4) {
            StGwGroundNode* node = &self->m_node[idx];
            node->timer -= deltaFrame;
            if (node->timer < f30) {
                node->timer = f30;
            }

            switch (node->state) {
            case 2:
                if (f30 == node->timer) {
                    if (randf__Fv() < param->m88) {
                        self->setNodeVisibility(true, 0, self->m_nodeId[node->counter + idx * 5], true, false);
                        PanelZone zone;
                        self->getNodePosition(&zone.position, 0, self->m_nodeId[node->counter + idx * 5]);
                        setCorner(zone.lo, zone.position.m_x - f31, f31 + zone.position.m_y);
                        setCorner(zone.hi, f31 + zone.position.m_x, zone.position.m_y - f31);
                        self->m_dz[idx] = g_aiMgr->setDangerZone(&zone.lo, &zone.hi, self->m_dz[idx], false, false);
                        node->timer = param->m7C;
                        node->state = 4;
                    } else {
                        node->timer = param->m84;
                    }
                }
                break;
            case 4:
                if (self->m27C == 1) {
                    self->fn_63_8808(idx);
                    node->unkB = 1;
                }
                if (f30 == node->timer) {
                    if (node->counter == 4 && self->fn_63_8BD0(idx) == 1) {
                        node->timer = param->m7C;
                        node->state = 3;
                    } else {
                        self->setNodeVisibility(false, 0, self->m_nodeId[node->counter + idx * 5], true, false);
                        disableNode(self, node, idx);
                        u8 c = node->counter + 1;
                        node->counter = c;
                        if (c == 5) {
                            self->disableAttack(idx);
                            node->state = 5;
                            node->counter = 4;
                            node->unkA = 15;
                            node->timer = k[8];
                            node->unkB = 0;
                        } else {
                            self->setNodeVisibility(true, 0, self->m_nodeId[c + idx * 5], true, false);
                            self->fn_63_8808(idx);
                            node->unkB = 1;
                            PanelZone zone;
                            self->getNodePosition(&zone.position, 0, self->m_nodeId[node->counter + idx * 5]);
                            setCorner(zone.lo, zone.position.m_x - f31, f31 + zone.position.m_y);
                            setCorner(zone.hi, f31 + zone.position.m_x, zone.position.m_y - f31);
                            self->m_dz[idx] = g_aiMgr->setDangerZone(&zone.lo, &zone.hi, self->m_dz[idx], false, false);
                            node->timer = param->m7C;
                        }
                    }
                }
                break;
            case 3:
                if (f30 == node->timer) {
                    u8 counter = node->counter;
                    if (counter == 0) {
                        node->timer = param->m80;
                        node->state = 4;
                    } else {
                        self->setNodeVisibility(false, 0, self->m_nodeId[counter + idx * 5], true, false);
                        disableNode(self, node, idx);
                        node->counter--;
                        self->setNodeVisibility(true, 0, self->m_nodeId[node->counter + idx * 5], true, false);
                        self->fn_63_8808(idx);
                        node->unkB = 1;
                        PanelZone zone;
                        self->getNodePosition(&zone.position, 0, self->m_nodeId[node->counter + idx * 5]);
                        setCorner(zone.lo, zone.position.m_x - f31, f31 + zone.position.m_y);
                        setCorner(zone.hi, f31 + zone.position.m_x, zone.position.m_y - f31);
                        self->m_dz[idx] = g_aiMgr->setDangerZone(&zone.lo, &zone.hi, self->m_dz[idx], false, false);
                        node->timer = param->m7C;
                    }
                }
                break;
            case 5:
                if (node->timer > k[9]) {
                    self->setNodeVisibility(true, 0, self->m_nodeId[node->counter + idx * 5], true, false);
                } else {
                    self->setNodeVisibility(false, 0, self->m_nodeId[node->counter + idx * 5], true, false);
                }
                if (self->m_dz[idx] != -1) {
                    fn_27_1F299C(g_aiMgr, self->m_dz[idx]);
                    self->m_dz[idx] = -1;
                }
                if (f30 == node->timer) {
                    if (node->unkA == 0) {
                        node->counter = 0;
                        node->timer = param->m84;
                        node->state = 2;
                        break;
                    }
                    --node->unkA;
                    node->timer = k[8];
                }
                break;
            }
            ++idx;
        }
    }
}


