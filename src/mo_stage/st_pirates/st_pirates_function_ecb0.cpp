#pragma force_active on
extern "C" const float lbl_52_rodata_280[];
extern "C" void fn_801109AC(void*);
extern "C" void fn_8011097C(void*);

struct BitFlags {
 unsigned char b0:1; unsigned char b1:1; unsigned char b2:1; unsigned char b3:1;
 unsigned char b4:1; unsigned char b5:1; unsigned char b6:1; unsigned char b7:1;
};
struct Flags { unsigned char pad[0x54]; BitFlags bits; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_52_E994();
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
    virtual void fn_52_E92C();
    virtual void fn_52_E9FC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8();
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
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
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_52_3694();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_52_3718();
    virtual void fn_52_3710();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_52_3708();
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
    virtual void fn_52_864();
    virtual void fn_52_A24();
    virtual void fn_52_EAC0();
    virtual void fn_52_ECB0();
    virtual void fn_52_F0D0();
    virtual void fn_52_F28C(int, int, int, float*);
    void setEnableCollisionStatus(bool);
    char pad40[0xc];
    void* collision;
    char pad50[0x1c];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[7];
    float* ref;
    char pad15c[8];
    unsigned char active;
    unsigned char counter;
    char pad166[2];
    unsigned char* command;
    unsigned char saved;
    char pad16d[3];
    unsigned char* countRef;
    unsigned char phase;
    char pad175[3];
    float timer;
    Flags* object17c;
    char pad180[4];
    Flags* object184;
    char pad188[8];
    unsigned char flag190;
};

extern "C" void fn_52_ECB0(Ground* self, float delta) {
    const float* k = lbl_52_rodata_280;
    if (self->command != 0) {
        self->timer -= delta;
        if (self->timer < k[0])
            self->timer = k[0];
        switch (self->state) {
        case 0:
            self->fn_52_F28C(3, 0, 1, 0);
            self->setVisibility(0);
            self->setEnableCollisionStatus(false);
            if (self->collision != 0)
                fn_801109AC(self->collision);
            self->state = 1;
        case 1:
            if (self->active == 1) {
                switch (self->phase) {
                case 0:
                    if (--self->counter == 0) {
                        self->fn_52_F28C(1, 1, 1, &self->timer);
                        self->setMotionFrame(k[1] - *self->ref, 0);
                        self->counter = *self->countRef;
                        self->flag190 = 0;
                    }
                    break;
                case 1:
                    if (--self->counter == 0) {
                        self->fn_52_F28C(2, 0, 1, &self->timer);
                        self->setMotionFrame(k[1] - *self->ref, 0);
                        self->counter = 1;
                        self->flag190 = 0;
                    }
                    break;
                case 2:
                    if (--self->counter == 0)
                        self->state = 0;
                    break;
                }
                if (*self->command != self->saved) {
                    switch (*self->command) {
                    case 9:
                        self->fn_52_F28C(0, 0, 1, &self->timer);
                        self->setMotionFrame(k[1] - *self->ref, 0);
                        self->counter = 3;
                        self->setVisibility(1);
                        if (!((self->flags >> 5) & 1)) {
                            self->setEnableCollisionStatus(true);
                            if (self->collision != 0)
                                fn_8011097C(self->collision);
                            if (self->object17c != 0) {
                                BitFlags bits = self->object17c->bits;
                                bits.b3 = 1;
                                bits.b1 = bits.b3;
                                self->object17c->bits = bits;
                            }
                        }
                        self->flag190 = 0;
                        break;
                    }
                    self->saved = *self->command;
                }
            } else {
                switch (self->phase) {
                case 0:
                    if (self->getMotionFrame(0) >= k[2]) {
                        if (self->object184 != 0) {
                            BitFlags bits = self->object184->bits;
                            bits.b3 = 1;
                            bits.b1 = bits.b3;
                            self->object184->bits = bits;
                        }
                    }
                    break;
                case 2:
                    if (self->object184 != 0) {
                        BitFlags bits = self->object184->bits;
                        bits.b0 = 0;
                        bits.b3 = bits.b0;
                        bits.b1 = bits.b3;
                        self->object184->bits = bits;
                    }
                    if (self->getMotionFrame(0) >= k[3]) {
                        self->setEnableCollisionStatus(false);
                        if (self->collision != 0)
                            fn_801109AC(self->collision);
                    } else if (self->getMotionFrame(0) >= k[4]) {
                        if (self->object17c != 0) {
                            BitFlags bits = self->object17c->bits;
                            bits.b0 = 0;
                            bits.b3 = bits.b0;
                            bits.b1 = bits.b3;
                            self->object17c->bits = bits;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}
