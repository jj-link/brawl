#pragma force_active on

extern "C" {
extern const float lbl_52_rodata_2D0;
extern const float lbl_52_rodata_2D8;
}

struct Base {
    unsigned char pad[0x3c];
};

struct StateObj {
    unsigned char pad[0x54];
    unsigned char bitA : 1;
    unsigned char bitB : 1;
    unsigned char bitPad : 1;
    unsigned char bitC : 1;
    unsigned char rest : 4;
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
    virtual void fn_52_102EC();
    virtual void fn_52_10344();
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
    virtual void setNodeVisibilityAll(bool, unsigned long);
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
    virtual void getMotionFrame();
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
    virtual void fn_52_10408();
    virtual void fn_52_10628();
    virtual void fn_52_10A14();
    virtual void fn_52_10B04(int, int, int, float*);

    unsigned char pad40[0x2c];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char pad6d[0xe3];
    unsigned char state;
    unsigned char pad151[7];
    float* p158;
    unsigned char pad15c[4];
    unsigned char u160;
    unsigned char u161;
    unsigned char pad162[6];
    unsigned char* p168;
    unsigned char pad16c[4];
    unsigned char* p170;
    unsigned char u174;
    unsigned char pad175[7];
    StateObj* p17c;
    unsigned char u180;
    unsigned char pad181[3];
    float f184;

    void setEnableCollisionStatus(bool enable);
};

extern "C" void fn_52_10628(Ground* self, float delta) {
    self->f184 -= delta;
    if (self->f184 < lbl_52_rodata_2D0) {
        self->f184 = lbl_52_rodata_2D0;
    }

    switch (self->state) {
    case 0:
        self->fn_52_10B04(1, 1, 1, 0);
        self->state = 1;
        break;

    case 1:
        if (self->u160 == 1) {
            unsigned int r31 = 0x11;
            int r30 = 1;

            switch (self->u180) {
            case 7:
            case 10:
            case 13:
                r31 = 0;
                break;
            case 5:
            case 8:
            case 15:
                r31 = 2;
                break;
            case 6:
            case 9:
            case 12:
                r31 = 3;
                break;
            case 4:
            case 11:
            case 14:
                r31 = 1;
                break;
            case 16:
                if (--self->u161 == 0) r31 = 0;
                break;
            }

            unsigned char s = *self->p168;
            if (s != self->u174) {
                unsigned int saved = r31;
                switch (s) {
                case 1:
                    switch (self->u180) {
                    case 0: r31 = 4; break;
                    case 1: break;
                    case 2: r31 = 0xB; break;
                    case 3: r31 = 0xE; break;
                    case 16: r31 = 4; break;
                    }
                    break;
                case 2:
                    switch (self->u180) {
                    case 0: r31 = 5; break;
                    case 1: r31 = 8; break;
                    case 3: r31 = 0xF; break;
                    case 16: r31 = 4; break;
                    }
                    break;
                case 3:
                    switch (self->u180) {
                    case 0: r31 = 6; break;
                    case 1: r31 = 9; break;
                    case 2: r31 = 0xC; break;
                    case 16: r31 = 4; break;
                    }
                    break;
                case 4:
                    break;
                case 5:
                    switch (self->u180) {
                    case 1: r31 = 7; break;
                    case 2: r31 = 0xA; break;
                    case 3: r31 = 0xD; break;
                    }
                    break;
                case 6:
                    r31 = 0x10;
                    self->u161 = 3;
                    break;
                }
                if (r31 != (unsigned char)saved) {
                    r30 = 0;
                }
                self->u174 = *self->p168;
            }

            unsigned char* p170 = self->p170;
            if (p170 != 0) {
                if (*p170 == 1) {
                    if (!self->enabled) {
                        self->setNodeVisibilityAll(true, 0);
                        self->setVisibility(1);
                        self->setEnableCollisionStatus(true);
                        StateObj* o = self->p17c;
                        if (o != 0) {
                            o->bitC = 1;
                            o->bitB = o->bitC;
                        }
                    }
                } else if (self->enabled) {
                    self->setVisibility(0);
                    self->setEnableCollisionStatus(false);
                    StateObj* o = self->p17c;
                    if (o != 0) {
                        o->bitA = 0;
                        o->bitC = o->bitA;
                        o->bitB = o->bitC;
                    }
                }
            }

            if (r31 != 0x11) {
                self->fn_52_10B04(r31, r30, 1, &self->f184);
                float* p = self->p158;
                self->setMotionFrame(lbl_52_rodata_2D8 - *p, 0);
            }
        }
        break;
    }
}
