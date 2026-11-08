#pragma force_active on

extern "C" const float lbl_49_rodata_138;
extern "C" void playFrame__Q28StSeUtil5SeSeqFlf(void*, long, float);
extern "C" void playFrame__Q28StSeUtil5SeSeqFlff(void*, long, float, float);

struct Ret {
    unsigned char pad0[0x18];
    float value;
};

struct Ground_base { char pad[0x3c]; };
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
    virtual void fn_49_C2B8();
    virtual void fn_49_C324();
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
    virtual void fn_49_1900();
    virtual void startup();
    virtual void setNode();
    virtual void fn_49_4AC();
    virtual Ret* fn_49_18F8();
    virtual void fn_49_18F4();
    virtual void fn_49_13A8();
    virtual void fn_49_18EC();
    virtual void fn_49_18E0();
    virtual void fn_49_18D0();
    virtual void fn_49_18C0();
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
    virtual void fn_49_18BC();
    virtual void fn_49_18B8();
    virtual void fn_49_18B0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_49_18A8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_49_192C();
    virtual void fn_49_1924();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_49_191C();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_49_C398();
    virtual void fn_49_C560();
    virtual void fn_49_C610(int, int, int, void*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char pad158[0x164 - 0x158];
    unsigned char* ptr;
    unsigned char pad168[4];
    unsigned char buffer[4];
    unsigned char seq[0x20];
};

extern "C" void fn_49_C398(Ground* self, float delta) {
    Ret* r = self->fn_49_18F8();
    if (r == 0) return;

    self->timer = self->timer - delta;
    if (self->timer < lbl_49_rodata_138)
        self->timer = lbl_49_rodata_138;

    switch (self->state) {
    case 0:
        self->fn_49_C610(1, 1, 0, 0);
        self->setVisibility(0);
        self->state = 1;
        break;
    case 1:
        if (*self->ptr == 0) {
            self->fn_49_C610(0, 1, 0, self->buffer);
            self->setVisibility(1);
            playFrame__Q28StSeUtil5SeSeqFlff(self->seq, 0, self->getMotionFrame(0), lbl_49_rodata_138);
            self->timer = r->value;
            self->state = 6;
        }
        break;
    case 6:
        playFrame__Q28StSeUtil5SeSeqFlf(self->seq, 0, self->getMotionFrame(0));
        if (lbl_49_rodata_138 == self->timer) {
            *self->ptr = 0xA;
            self->state = 0;
        }
        break;
    }
}
