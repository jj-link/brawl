#pragma force_active on
extern "C" {
extern const float lbl_63_rodata_A8;
extern const float lbl_63_rodata_AC;
extern void* g_aiMgr;
void fn_27_1F299C(void*, int);
}

struct GroundParam {
    unsigned char pad0[0x70];
    float f70;
    unsigned char pad74[4];
    float f78;
    unsigned char pad7C[8];
    float f84;
};

struct Ground_base {
    unsigned char pad[0x3C];
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
    virtual void fn_63_65C8();
    virtual void fn_63_66AC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping(unsigned long);
    virtual void setVisibilityAttachedEffect(unsigned long);
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
    virtual GroundParam* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility(bool, unsigned long, unsigned long, bool, bool);
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
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
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
    virtual void disableHit(unsigned long, unsigned long);
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
    virtual void fn_63_2D00();
    virtual void fn_63_7C78();
    virtual void fn_63_2ED8(int, int, int, float*);
    virtual void fn_63_C50();
    virtual void fn_63_C58();
    virtual void fn_63_6750();
    virtual void fn_63_6BF8();
    virtual void fn_63_72C0(float);
    virtual void fn_63_75EC(float);
    virtual void fn_63_7DE4();
    virtual void fn_63_8808();
    virtual void fn_63_86B4();
    virtual void fn_63_8968();

    unsigned char pad40[0x24];
    float x64;
    unsigned char pad68[4];
    unsigned char x6C;
    unsigned char pad6D[0x150 - 0x6D];
    unsigned char state;
    unsigned char pad151[3];
    float x154;
    unsigned char pad158[8];
    float x160;
    float x164;
    unsigned char pad168[0xC];
    unsigned char* flagPtr;
    unsigned char flag178;
    unsigned char pad179[3];
    int x17C;
    unsigned char pad180[0x1D0 - 0x180];
    int x1D0;
    unsigned char pad1D4[0x204 - 0x1D4];
    float x204;
    unsigned char pad208[4];
    unsigned char x20C;
    unsigned char x20D;
    unsigned char pad20E[1];
    unsigned char x20F;
    float x210;
    unsigned char pad214[4];
    unsigned char x218;
    unsigned char x219;
    unsigned char pad21A[1];
    unsigned char x21B;
    float x21C;
    unsigned char pad220[4];
    unsigned char x224;
    unsigned char x225;
    unsigned char pad226[1];
    unsigned char x227;
    float x228;
    unsigned char pad22C[4];
    unsigned char x230;
    unsigned char x231;
    unsigned char pad232[1];
    unsigned char x233;
    float x234;
    float x238;
    unsigned char x23C;
    unsigned char x23D;
    unsigned char pad23E[1];
    unsigned char x23F;
    unsigned char pad240[0x1C];
    float x25C;
    float x260;
    float x264;
    float x268;
    float x26C;
    float x270;
    unsigned char x274;
    unsigned char pad275[3];
    int x278;
    unsigned char x27C;
    unsigned char pad27D[0x17];
    int x294;
    int x298;
    int x29C;
    int x2A0;
};

extern "C" void fn_63_6BF8(Ground* self, float delta) {
    GroundParam* p = self->fn_63_3370();
    if (p != 0) {
        self->x154 -= delta;
        if (self->x154 < lbl_63_rodata_A8) {
            self->x154 = lbl_63_rodata_A8;
        }

        switch (self->state) {
        case 0:
            self->fn_63_2ED8(1, 0, 1, 0);
            self->setVisibility(0);
            if (self->x23F == 1) {
                self->disableAttack(4);
            }
            if (self->x20F == 1) {
                self->disableAttack(0);
            }
            if (self->x21B == 1) {
                self->disableAttack(1);
            }
            if (self->x227 == 1) {
                self->disableAttack(2);
            }
            if (self->x233 == 1) {
                self->disableAttack(3);
            }
            if (self->x278 != -1) {
                self->setNodeVisibility(true, 0, self->x278, true, false);
                self->x274 = 1;
                self->x25C = lbl_63_rodata_A8;
                self->x260 = lbl_63_rodata_A8;
                self->x264 = lbl_63_rodata_A8;
                self->x268 = lbl_63_rodata_A8;
                self->x26C = lbl_63_rodata_A8;
                self->x270 = lbl_63_rodata_A8;
            }
            self->setNodeVisibility(false, 0, self->x1D0, true, true);
            self->setNodeVisibility(false, 0, self->x17C, true, true);
            self->disableHit(0, 0);
            self->disableHit(1, 0);
            self->disableHit(2, 0);
            self->disableHit(3, 0);
            self->state = 1;
            break;
        case 1:
            if (*self->flagPtr == self->flag178) {
                self->fn_63_8968();
                self->x234 = p->f70;
                self->x238 = p->f78;
                self->x23D = 6;
                self->x23F = 0;
                self->x204 = p->f84;
                self->x20D = 2;
                self->x20C = 0;
                self->x20F = 0;
                self->x210 = p->f84;
                self->x219 = 2;
                self->x218 = 0;
                self->x21B = 0;
                self->x21C = p->f84;
                self->x225 = 2;
                self->x224 = 0;
                self->x227 = 0;
                self->x228 = p->f84;
                self->x231 = 2;
                self->x230 = 0;
                self->x233 = 0;
                self->fn_63_2ED8(0, 1, 1, &self->x164);
                self->setMotionFrame(self->x164, 0);
                self->x160 = self->x164;
                if (self->x64 > lbl_63_rodata_A8) {
                    self->x64 = self->x64 * lbl_63_rodata_AC;
                }
                self->x27C = 0;
                self->x278 = -1;
                self->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            if (*self->flagPtr != self->flag178) {
                self->fn_63_2ED8(0, 0, 1, &self->x164);
                if (self->x64 < lbl_63_rodata_A8) {
                    self->x64 = self->x64 * lbl_63_rodata_AC;
                }
                self->disableHit(0, 0);
                self->disableAttack(0);
                self->x20F = 0;
                self->disableHit(1, 0);
                self->disableAttack(1);
                self->x21B = 0;
                self->disableHit(2, 0);
                self->disableAttack(2);
                self->x227 = 0;
                self->disableHit(3, 0);
                self->disableAttack(3);
                self->x233 = 0;
                self->disableHit(self->x23C, 0);
                self->state = 4;
                break;
            }
            if (!(((self->x6C) >> 7) & 1)) {
                self->setVisibility(1);
            }
            if (self->x27C == 0) {
                if (self->getMotionFrame(0) > self->x160) {
                    self->fn_63_2ED8(1, 0, 0, 0);
                    self->x27C = 1;
                } else {
                    self->x160 = self->getMotionFrame(0);
                }
            }
            self->fn_63_72C0(delta);
            self->fn_63_75EC(delta);
            break;
        case 4:
            if (self->getMotionFrame(0) >= self->x164) {
                if (self->x294 != -1) {
                    fn_27_1F299C(g_aiMgr, self->x294);
                }
                if (self->x298 != -1) {
                    fn_27_1F299C(g_aiMgr, self->x298);
                }
                if (self->x29C != -1) {
                    fn_27_1F299C(g_aiMgr, self->x29C);
                }
                if (self->x2A0 != -1) {
                    fn_27_1F299C(g_aiMgr, self->x2A0);
                }
                self->x294 = -1;
                self->x298 = -1;
                self->x29C = -1;
                self->x2A0 = -1;
                self->state = 0;
            }
            break;
        }
    }
}
