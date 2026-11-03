#include <revolution/OS/OSFastCast.h>
#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;

struct Base {
    char pad0[0x3C];
};

struct StageData {
    char pad0[0x10];
    float f10;
    float f14;
};

struct Ground : Base {
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
    virtual void unused24();
    virtual void unused25();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(u8 unk1);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void unused38();
    virtual void startup();
    virtual void setNode();
    virtual void unused41();
    virtual StageData* fn_46_4858();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
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
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void setMotionRatio();
    virtual void fn_46_6174(u8 unk1, float unk2);
    virtual float fn_46_61A0(u8 unk1);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void unused75();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void unused82();
    virtual void unused83();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void unused91();
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
    virtual void fn_46_4630();
    virtual void fn_46_5ED8();
    virtual void fn_46_5910();
    virtual void fn_46_5FBC(u8 a, u8 b, u8 c, float* d);

    char pad40[0x4C - 0x40];
    void* p4C;
    char pad50[0x64 - 0x50];
    float f64;
    char pad68[0x6C - 0x68];
    u8 u6C;
    char pad6D[0x150 - 0x6D];
    u8 u150;
    char pad151[0x154 - 0x151];
    float f154;
    char pad158[0x164 - 0x158];
    float f164;
    float f168;
    float f16C;
    float* p170;
    u8* p174;
    u8 u178;
    u8 u179;
    char pad17A[0x17C - 0x17A];
    float f17C;
    char pad180[0x184 - 0x180];
    float f184;
    float f188;
};

extern "C" {
extern const float lbl_46_rodata_110[];
float fn_801622C4(float);
void fn_8011097C(void*);
void fn_801109AC(void*);
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
}

extern "C" void fn_46_5910(Ground* self, float dt) {
    const float* c = lbl_46_rodata_110;
    StageData* d = self->fn_46_4858();
    if (d != 0) {
        float t = self->f154 - dt;
        self->f154 = t;
        if (t < c[0]) {
            self->f154 = c[0];
        }
        if (*self->p174 != self->u178) {
            self->u150 = 0;
        }
        switch (*self->p174) {
        case 0:
            switch (self->u150) {
            case 2:
                break;
            case 0:
                self->fn_46_5FBC(0, 1, 1, &self->f188);
                self->fn_46_6174(0, self->f188);
                self->f184 = self->f188;
                if (self->f64 > c[0]) {
                    self->f64 = self->f64 * c[1];
                }
                self->f154 = d->f10;
                self->u150 = 1;
                break;
            case 1: {
                float v = self->fn_46_61A0(0);
                if (v > self->f184) {
                    self->fn_46_5FBC(1, 0, 1, 0);
                    self->u150 = 3;
                } else {
                    if (!(((u8)self->u6C >> 7) & 1)) {
                        self->setVisibility(1);
                        setEnableCollisionStatus__6GroundFb(self, true);
                        if (self->p4C != 0) {
                            fn_8011097C(self->p4C);
                        }
                    }
                    self->f184 = self->fn_46_61A0(0);
                }
                break;
            }
            case 3:
                if (self->u179 == 2 && c[2] == self->f17C) {
                    *self->p174 = 1;
                }
                break;
            }
            self->f17C = c[2] - self->f154 / d->f10;
            if (self->f17C < c[0]) {
                self->f17C = c[0];
            }
            if (self->f17C > c[2]) {
                self->f17C = c[2];
            }
            {
                u16 spA = (u16)(c[3] * self->f17C);
                float r = fn_801622C4(c[4] * __OSu16tof32(&spA));
                float k = d->f14;
                self->f168 = -k + k * r;
                self->f164 = c[0];
                self->f16C = c[0];
                if (self->u179 == 2) {
                    *self->p170 = r;
                }
            }
            break;
        case 1:
            switch (self->u150) {
            case 1:
                break;
            case 0:
                self->fn_46_5FBC(1, 0, 1, 0);
                self->u150 = 1;
                break;
            }
            if (self->u179 == 2) {
                *self->p170 = c[2];
            }
            break;
        case 2:
            switch (self->u150) {
            case 2:
                break;
            case 0:
                self->fn_46_5FBC(0, 0, 1, &self->f188);
                if (self->f64 < c[0]) {
                    self->f64 = self->f64 * c[1];
                }
                self->f154 = d->f10;
                self->u150 = 1;
                break;
            case 1:
                if (self->fn_46_61A0(0) >= self->f188) {
                    self->fn_46_5FBC(1, 0, 1, 0);
                    self->setVisibility(0);
                    setEnableCollisionStatus__6GroundFb(self, false);
                    if (self->p4C != 0) {
                        fn_801109AC(self->p4C);
                    }
                    self->u150 = 3;
                }
                break;
            case 3:
                if (self->u179 == 2 && c[2] == self->f17C) {
                    *self->p174 = 3;
                }
                break;
            }
            self->f17C = c[2] - self->f154 / d->f10;
            if (self->f17C < c[0]) {
                self->f17C = c[0];
            }
            if (self->f17C > c[2]) {
                self->f17C = c[2];
            }
            {
                u16 spA = (u16)(c[3] * self->f17C);
                float r = fn_801622C4(c[4] * __OSu16tof32(&spA));
                float k = d->f14;
                self->f168 = -k * r;
                self->f164 = c[0];
                self->f16C = c[0];
                if (self->u179 == 2) {
                    *self->p170 = c[2] - r;
                }
            }
            break;
        default:
            switch (self->u150) {
            case 1:
                break;
            case 0:
                self->fn_46_5FBC(1, 0, 1, 0);
                self->setVisibility(0);
                setEnableCollisionStatus__6GroundFb(self, false);
                if (self->p4C != 0) {
                    fn_801109AC(self->p4C);
                }
                self->f168 = -d->f14;
                self->u150 = 1;
                self->f164 = c[0];
                self->f16C = c[0];
                break;
            }
            break;
        }
        self->u178 = *self->p174;
    }
}
