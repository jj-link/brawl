#pragma force_active on
#include <gr/gr_gimmick.h>

extern "C" const float lbl_57_rodata_16C;

namespace matching {
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_57_3F4C();
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
    virtual void fn_57_3ED4();
    virtual void fn_57_400C();
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
    virtual void fn_57_3F50();
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
    virtual bool getNodePosition(Vec3f*, unsigned long, unsigned long);
    virtual void getNodePosition_2();
    virtual bool getNodeMatrix(Matrix*, unsigned long, unsigned long);
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
    virtual float getMotionFrame(unsigned long);
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
    virtual void fn_57_650();
    virtual void fn_57_658();
    virtual void fn_57_42B0(float);
    virtual void fn_57_43F0(float);
    virtual void fn_57_45AC(float);

    char pad40[0x2c];
    unsigned char flags;
    char pad6d[0xf7];
    Matrix* matrices;
    Vec3f* positions;
    unsigned char state;
    char pad16d[7];
    unsigned long node0, node1, node2, node3;
    char pad184[8];
    unsigned long matrixNode0, matrixNode1, matrixNode2, matrixNode3;
};
}

extern "C" void fn_57_400C(matching::Ground* self, float delta) {
    reinterpret_cast<grGimmick*>(self)->grGimmick::update(delta);
    self->fn_57_42B0(delta);
    self->fn_57_43F0(delta);
    self->fn_57_45AC(delta);
    self->updateG3dProcCalcWorld();
    self->flags &= ~2;
    if (self->matrices) {
        self->getNodeMatrix(&self->matrices[0], 0, self->matrixNode0);
        self->getNodeMatrix(&self->matrices[1], 0, self->matrixNode1);
        self->getNodeMatrix(&self->matrices[2], 0, self->matrixNode2);
        self->getNodeMatrix(&self->matrices[4], 0, self->matrixNode3);
    }
    if (self->positions) {
        switch (self->state) {
        case 0:
            if (!(self->getMotionFrame(0) < lbl_57_rodata_16C)) {
                self->getNodePosition(&self->positions[0], 0, self->node0);
                self->getNodePosition(&self->positions[1], 0, self->node1);
                self->getNodePosition(&self->positions[2], 0, self->node2);
                self->getNodePosition(&self->positions[3], 0, self->node3);
            }
            break;
        case 1:
            self->getNodePosition(&self->positions[0], 0, self->node0);
            self->getNodePosition(&self->positions[1], 0, self->node1);
            self->getNodePosition(&self->positions[2], 0, self->node2);
            self->getNodePosition(&self->positions[3], 0, self->node3);
            break;
        }
    }
}
