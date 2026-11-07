#pragma force_active on

#include <mt/mt_vector.h>
#include <st/se_util.h>

struct Obj {
    char pad[0x14];
    float f14;
    float f18;
};

struct GroundBase {
    char pad[0x3c];
};

class Ground : public GroundBase {
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
    virtual void fn_77_1B9C();
    virtual void fn_77_1C3C();
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
    virtual void fn_77_1004();
    virtual void startup();
    virtual void setNode();
    virtual void fn_77_478();
    virtual Obj* fn_77_FFC();
    virtual void fn_77_FF8();
    virtual void fn_77_EE8();
    virtual void fn_77_FF0();
    virtual void fn_77_FE4();
    virtual void fn_77_FD4();
    virtual void fn_77_FC4();
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
    virtual void fn_77_FC0();
    virtual void fn_77_FBC();
    virtual void fn_77_FB4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_77_FAC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_77_1030();
    virtual void fn_77_1028();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_77_1020();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack(unsigned long);
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
    virtual void fn_77_1FBC();
    virtual void fn_77_1CF4();
    virtual void fn_77_2014();
    virtual void fn_77_20F8();
    virtual void fn_77_21C4();
    virtual void fn_77_25A0();
    virtual void fn_77_26F0(int, int, int, void*);

    char pad40[0x150 - 0x40];
    unsigned char state150;
    char pad151[0x154 - 0x151];
    float f154;
    char pad158[0x15c - 0x158];
    float f15c;
    float f160;
    float f164;
    char pad168[0x176 - 0x168];
    unsigned char u176;
};

extern "C" {
float randf__Fv();
extern const float lbl_77_rodata_48[];
}

extern "C" void fn_77_1CF4(Ground* self, float f) {
    const float* c = lbl_77_rodata_48;
    Obj* obj = self->fn_77_FFC();
    if (obj == 0) {
        return;
    }
    self->f154 = self->f154 - f;
    if (self->f154 < c[0]) {
        self->f154 = c[0];
    }
    self->f15c = self->f15c - f;
    if (self->f15c < c[0]) {
        self->f15c = c[0];
    }
    switch (self->state150) {
    case 0:
        self->fn_77_26F0(1, 0, 1, 0);
        self->disableAttack(0);
        self->u176 = 0;
        self->f154 = c[5];
        self->state150 = 1;
        break;
    case 1:
        if (c[0] == self->f154) {
            self->fn_77_26F0(0, 0, 1, &self->f15c);
            float frame = self->getMotionFrame(0);
            ((StSeUtil::SeSeq*)((char*)self + 0x17c))->playFrame(0, frame, c[0]);
            self->f160 = c[0];
            float r = randf__Fv();
            float d = obj->f18 - obj->f14;
            self->f164 = obj->f14 + d * r;
            self->state150 = 2;
        }
        break;
    case 2:
        if (c[0] == self->f15c) {
            self->state150 = 0;
            break;
        }
        self->f160 = self->f160 + f;
        if (self->f160 > c[4]) {
            self->disableAttack(0);
            self->u176 = 0;
        } else if (self->f160 > c[6]) {
            self->fn_77_25A0();
        } else if (self->f160 > c[7]) {
            self->disableAttack(0);
            self->u176 = 0;
        } else if (self->f160 > c[8]) {
            self->fn_77_25A0();
        } else {
            self->disableAttack(0);
            self->u176 = 0;
        }
        ((StSeUtil::SeSeq*)((char*)self + 0x17c))->playFrame(0, self->getMotionFrame(0));
        break;
    }
}
