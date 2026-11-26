#include <types.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on

#pragma pool_data on
#pragma pool_fp_consts on

struct StParams {
    char pad0[0x58];
    float f58;
    float f5c;
    float f60;
    float f64;
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
    virtual void fn_71_5848();
    virtual void fn_71_2D18();
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
    virtual void fn_71_2B8C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_71_85C();
    virtual StParams* fn_71_2B84();
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
    virtual float getMotionFrame(unsigned long);
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_71_58BC();
    virtual void fn_71_2D90();
    virtual void fn_71_2E5C(int, int, int, void*);

    char pad40[0x150 - 0x40];
    unsigned char st150;
    char pad151[0x154 - 0x151];
    float f154;
    Vec3f* p158;
    unsigned char* p15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    unsigned char b184;
    char pad185[2];
    unsigned char b187;
    float f188;
    float f18c;
    unsigned char b190;
    char pad191[3];
    s32 st194;
};

#define randf__Fv randf
#define playFrame__Q28StSeUtil5SeSeqFlf(seq, idx, frame) \
    (((StSeUtil::SeSeq*)(seq))->playFrame(idx, frame))
#define playFrame__Q28StSeUtil5SeSeqFlff(seq, idx, frame, rate) \
    (((StSeUtil::SeSeq*)(seq))->playFrame(idx, frame, rate))

extern "C" void fn_71_58BC(Ground* self, float dt) {
    float pool0 = 0.0f;
    float pool1 = 1.0f;
    double conversionBias = 4503599627370496.0;
    float pool4 = 43.0f;
    float pool5 = 125.0f;
    float pool6 = 201.0f;
    float pool7 = 221.0f;
    float pool8 = 268.0f;
    float pool9 = 308.0f;
    float pool10 = 335.0f;
    float pool11 = 32.0f;
    float pool12 = 69.0f;
    float pool13 = 148.0f;
    float pool14 = 197.0f;
    float pool15 = 10.0f;
    float pool16 = 22.0f;
    float pool17 = 65.0f;
    float pool18 = 30.0f;
    float pool19 = 80.0f;
    float pool20 = 122.0f;
    float pool21 = 162.0f;
    float pool22 = 171.0f;
    float pool23 = 260.0f;
    float pool24 = 35.0f;
    float pool25 = 95.0f;
    float pool26 = 100.0f;
    float pool27 = 0.5f;
    float pool28 = 28.0f;
    float pool29 = 0.6f;
    float pool30 = 60.0f;
    float pool31 = 16384.0f;
    float pool32 = 0.00390625f;
    float pool33 = 1.1754943508222875e-38f;
    float pool34 = 1.40625f;
    float pool35 = 1.25f;
    float pool36 = 0.00001f;
    float pool37 = 50.0f;
    float pool38 = 0.35f;
    float pool39 = 45.0f;
    float pool40 = 90.0f;
    float pool41 = 0.7111111283302307f;
    float pool42 = -15.0f;
    float pool43 = 15.0f;
    float pool44 = 98.0f;
    float pool45 = -60.0f;
    float pool46 = 2.0f;
    StParams* p = self->fn_71_2B84();
    if (p == 0) {
        return;
    }

    float t = self->f154 - dt;
    self->f154 = t;
    if (t < 0.0f) {
        self->f154 = 0.0f;
    }

    float f31 = self->getMotionFrame(0);
    switch (self->st150) {
    case 0:
        self->fn_71_2E5C(6, 0, 1, 0);
        self->setVisibility(0);
        self->f160 = self->p158->m_x;
        self->f164 = self->p158->m_y;
        self->f168 = self->p158->m_z;
        self->st150 = 1;
        break;

    case 1:
        if (*self->p15c == 4) {
            self->fn_71_2E5C(0, 0, 1, (char*)self + 0x18c);
            f31 = 0.0f;
            self->f188 = f31;
            self->setVisibility(1);
            self->st194 = 0;
            {
                float fr = self->getMotionFrame(0);
                playFrame__Q28StSeUtil5SeSeqFlff(
                    (char*)self + 0x198, self->st194, fr, f31);
            }
            self->st150 = 6;
        }
        break;

    case 6:
        if (0.0f == self->f154) {
            self->b190 = 1;
        }
        break;
    }

    if (f31 >= self->f18c || f31 < self->f188) {
        switch (self->b187) {
        case 0:
            self->fn_71_2E5C(3, 1, 0, (char*)self + 0x18c);
            f31 = (self->st194 = 2, 0.0f);
            {
                float fr = self->getMotionFrame(0);
                playFrame__Q28StSeUtil5SeSeqFlff(
                    (char*)self + 0x198, self->st194, fr, f31);
            }
            {
                float rr = randf__Fv();
                float d = p->f5c - p->f58;
                self->f154 = p->f58 + d * rr;
                self->b190 = 0;
            }
            break;

        case 1: {
            u8 bn = self->b184;
            float step = 15.0f;
            float v = self->f170 + step;
            self->f170 = v;
            if (v >= self->f17c + step * (float)bn || v >= 60.0f) {
                float nv = self->f17c + 15.0f * (float)bn;
                self->f170 = nv;
                if (nv > 60.0f) {
                    self->f170 = 60.0f;
                }
                self->fn_71_2E5C(3, 1, 0, (char*)self + 0x18c);
                f31 = (self->st194 = 2, 0.0f);
                float fr = self->getMotionFrame(0);
                playFrame__Q28StSeUtil5SeSeqFlff(
                    (char*)self + 0x198, self->st194, fr, f31);
            }
            break;
        }

        case 2: {
            u8 bn = self->b184;
            float step = 15.0f;
            float v = self->f170 - step;
            self->f170 = v;
            if (v <= self->f17c - step * (float)bn || v <= -60.0f) {
                float nv = self->f17c - 15.0f * (float)bn;
                self->f170 = nv;
                if (nv < -60.0f) {
                    self->f170 = -60.0f;
                }
                self->fn_71_2E5C(3, 1, 0, (char*)self + 0x18c);
                f31 = (self->st194 = 2, 0.0f);
                float fr = self->getMotionFrame(0);
                playFrame__Q28StSeUtil5SeSeqFlff(
                    (char*)self + 0x198, self->st194, fr, f31);
            }
            break;
        }

        case 3:
        case 4:
        case 5: {
            u8 r = self->b187;
            if (self->b190 == 1) {
                u8 nr = r;
                float rv = randf__Fv();
                if (rv < p->f60) {
                    float v = self->f170;
                    if (v >= 60.0f) {
                        nr = 2;
                    } else if (v <= -60.0f) {
                        nr = 1;
                    } else if (randf__Fv() < p->f64) {
                        nr = 2;
                    } else {
                        nr = 1;
                    }
                    self->f178 = self->f16c;
                    self->f17c = self->f170;
                    self->f180 = self->f174;
                    float rr = randf__Fv();
                    self->b184 = (unsigned char)(int)(2.0f + 2.0f * rr);
                } else {
                    switch (self->b187) {
                    case 3:
                        nr = (randf__Fv() < 0.5f) ? 4 : 5;
                        break;
                    case 4:
                        nr = (randf__Fv() < 0.5f) ? 5 : 3;
                        break;
                    case 5:
                        nr = (randf__Fv() < 0.5f) ? 3 : 4;
                        break;
                    }
                }

                self->fn_71_2E5C(nr, 1, 1, (char*)self + 0x18c);
                f31 = 0.0f;
                switch (nr) {
                case 0: self->st194 = 0; break;
                case 1: self->st194 = 1; break;
                case 2: self->st194 = 1; break;
                case 3: self->st194 = 2; break;
                case 4: self->st194 = 3; break;
                case 5: self->st194 = 4; break;
                }
                if (self->st194 != -1) {
                    playFrame__Q28StSeUtil5SeSeqFlff(
                        (char*)self + 0x198, self->st194,
                        self->getMotionFrame(0), 0.0f);
                }
                float rr2 = randf__Fv();
                float d = p->f5c - p->f58;
                self->f154 = p->f58 + d * rr2;
                self->b190 = 0;
            }
            break;
        }
        }
    }

    if (self->st194 != -1) {
        playFrame__Q28StSeUtil5SeSeqFlf(
            (char*)self + 0x198, self->st194, self->getMotionFrame(0));
    }
    self->f188 = f31;
}
