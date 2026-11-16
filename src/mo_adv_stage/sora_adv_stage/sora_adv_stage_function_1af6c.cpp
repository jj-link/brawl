#include <types.h>

#pragma force_active on

extern "C" {
void update__9grGimmickFf(void*, float);
void updateCallback__9grGimmickFUl(void*, unsigned long);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
extern const float lbl_40_rodata_280;
}

struct grYakumono_base {
    char pad[0x3C];
};

class AnimSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void setFrame(float f);
};

struct gfModelAnimation {
    char pad0[0xC];
    AnimSub* unkC;
};

class grYakumono : public grYakumono_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void fn_40_1B260();
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
    virtual void fn_40_1A760();
    virtual void fn_40_1AF6C();
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
    virtual void getModelCount();
    virtual void fn_40_1A868();
    virtual void setNode();
    virtual void setStageData();
    virtual void getStageData();
    virtual void initStageData();
    virtual void setMdlIndex();
    virtual void getMdlIndex();
    virtual void isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
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
    virtual void fn_40_1AE74();
    virtual void setInitializeInfo();
    virtual void getInitializeInfo();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void adventureEventGetItem();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData();
    virtual void getGimmickData();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void getTransparencyFlag();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void fn_40_1B91C();
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
    virtual void fn_40_1B144(float delta);

    char pad40[4];
    void** m44;
    gfModelAnimation** m48;
    char pad4C[0x122];
    u8 m16E;
    char pad16F[1];
    float m170;
    char pad174[0x30];
    s8 m1A4;
    char pad1A5[3];
    float m1A8;
    s32 m1AC;
    s32 m1B0;
};

extern "C" void fn_40_1AF6C(grYakumono* self, float delta) {
    update__9grGimmickFf(self, delta);
    switch (self->m1A4) {
    case 2:
        break;
    case 0:
        (*self->m48)->unkC->setFrame(self->m1A8);
        self->m1A8 += delta;
        if (self->m1A8 >= (float)self->m1AC) {
            self->m1A4 = 2;
            self->m1A8 = lbl_40_rodata_280;
        }
        break;
    case 1:
        (*self->m48)->unkC->setFrame(self->m1A8);
        self->m1A8 += delta;
        if (self->m1A8 >= (float)self->m1B0) {
            self->m1A4 = 2;
            self->m1A8 = lbl_40_rodata_280;
            unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*self->m48, *self->m44);
        }
        break;
    }
    self->fn_40_1B144(delta);
    if (self->m16E != 0) {
        self->m170 -= delta;
        if (self->m170 <= lbl_40_rodata_280) {
            self->enableArea();
            self->m16E = 0;
            self->m170 = lbl_40_rodata_280;
        }
    }
    updateCallback__9grGimmickFUl(self, 0);
}
