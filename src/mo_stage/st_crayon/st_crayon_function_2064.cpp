#pragma force_active on
extern "C" {
float randf__Fv();
void fn_56_106C(void* self, float delta);
void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
void unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void* self, void* mdl);
extern const float lbl_56_rodata_58[];
}

struct Params { float f0; float f4; float f8; float fc; float f10; float f14; float f18; };

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
    virtual void fn_56_1FB0();
    virtual void fn_56_2064();
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
    virtual void fn_56_2024();
    virtual void setNode();
    virtual void setStageData();
    virtual Params* getStageData();
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
    virtual void setInitializeFlag();
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
    virtual void fn_56_11CC();
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
    virtual void fn_56_2368(float dt);
    virtual void fn_56_2574(float dt);
    virtual void fn_56_2780(float dt);

    char pad40[4];
    void** p44;
    void** p48;
    char pad4c[0x164 - 0x4c];
    void* p164;
    char pad168[4];
    int i16C;
    unsigned char b170;
    unsigned char b171;
    unsigned char b172;
    unsigned char b173;
    float f174;
    float f178;
    float f17C;
};

extern "C" void fn_56_2064(Ground* self, float dt) {
    const float* d = lbl_56_rodata_58;
    fn_56_106C(self, dt);
    Params* p = self->getStageData();
    if (p == 0) return;
    switch ((int)self->b170) {
    case 0:
        self->f178 = p->f10 + (p->f18 - p->f14) * randf__Fv();
        self->f17C = p->f0 + (p->f8 - p->f4) * randf__Fv();
        self->p164 = self->p44[0];
        if (self->p164 == 0) return;
        self->i16C = (int)self->p48[0];
        if (self->i16C != 0) unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(self->p164, self->p48);
        self->p164 = self->p44[1];
        if (self->p164 == 0) return;
        self->i16C = (int)self->p48[1];
        if (self->i16C != 0) unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(self->p164, self->p48);
        self->p164 = self->p44[2];
        if (self->p164 == 0) return;
        void* r28 = (char*)self + 0xD0;
        if (r28 == 0) return;
        *(void**)((char*)self->p164 + 0x11C) = r28;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(self->p164, 1);
        *(short*)((char*)self->p164 + 0x122) = (short)(*(int*)(*(void**)((char*)r28 + 4)));
        self->b170 = self->b170 + 1;
        break;
    case 1:
    default:
        break;
    }
    if (self->b171 == 0 && self->b172 == 0) {
        self->f178 = self->f178 - dt;
    }
    if (self->f178 < d[0]) {
        self->f178 = p->f14 + (p->f18 - p->f14) * randf__Fv();
        if (randf__Fv() < d[1]) {
            self->b171 = 1;
        } else {
            self->b172 = 1;
        }
    }
    if (self->b173 == 0) {
        self->f17C = self->f17C - dt;
    }
    if (self->f17C < d[0]) {
        self->f17C = p->f4 + (p->f8 - p->f4) * randf__Fv();
        float r = randf__Fv();
        self->b173 = 1;
        self->f174 = d[2] + d[3] * r;
    }
    self->fn_56_2368(dt);
    self->fn_56_2574(dt);
    self->fn_56_2780(dt);
}
