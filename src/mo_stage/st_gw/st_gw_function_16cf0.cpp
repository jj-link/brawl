#pragma force_active on

extern "C" {
extern const float lbl_63_rodata_230[];
}

struct Ground_base {
    char pad[0x3c];
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
    virtual void fn_63_16C18();
    virtual void fn_63_16C70();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual void* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
    virtual int getNodeIndex(unsigned long, const char*);
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
    virtual void fn_63_2D00();
    virtual void fn_63_171FC();
    virtual void fn_63_2ED8(int, int, int, void*);

    unsigned char pad40[0x64 - 0x40];
    float f64;
    unsigned char pad68[0x150 - 0x68];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* p158;
    unsigned char b15c;
    unsigned char pad15d[7];
    float f164;
    unsigned char pad168[0x178 - 0x168];
    unsigned char* p178;
    unsigned char pad17c[4];
    unsigned char b180;
    unsigned char pad181[3];
    int i184;
    int i188;
    int i18c;
    unsigned char b190;
    unsigned char b191;
};

extern "C" void fn_63_16CF0(Ground* obj, float delta) {
    const float* c = lbl_63_rodata_230;

    if (obj->fn_63_3370() != 0) {
        obj->timer -= delta;
        if (obj->timer < c[0])
            obj->timer = c[0];

        switch (obj->state) {
        case 0:
            obj->fn_63_2ED8(0, 0, 1, &obj->f164);
            obj->setMotionFrame(obj->f164, 0);
            obj->setVisibility(0);
            obj->state = 1;
            return;

        case 1:
            if (*obj->p158 == obj->b15c) {
                switch (obj->b180) {
                case 0x0c:
                    obj->i184 = obj->getNodeIndex(0, "Diver_Left_Hand_02");
                    obj->i188 = obj->getNodeIndex(0, "Diver_Left_Hand_01");
                    obj->i18c = obj->getNodeIndex(0, "Diver_Left_Hand_03");
                    break;
                case 0x0f:
                    obj->i184 = obj->getNodeIndex(0, "Diver_Right_Hand_02");
                    obj->i188 = obj->getNodeIndex(0, "Diver_Right_Hand_01");
                    obj->i18c = obj->getNodeIndex(0, "Diver_Right_Hand_03");
                    break;
                }
                obj->state = 2;
                return;
            }
            break;

        case 2:
            if (*obj->p158 != obj->b15c) {
                obj->state = 0;
                return;
            }
            if (obj->b180 == *obj->p178) {
                obj->fn_63_2ED8(1, 0, 0, 0);
                obj->setVisibility(1);
                switch (obj->b180) {
                case 0x0c:
                case 0x0f:
                    obj->setNodeVisibility(true, 0, obj->i184, true, false);
                    obj->setNodeVisibility(false, 0, obj->i188, true, false);
                    obj->setNodeVisibility(false, 0, obj->i18c, true, false);
                    obj->b190 = 0;
                    obj->b191 = 0;
                    obj->timer = c[1];
                    break;
                }
                obj->state = 3;
                return;
            }
            break;

        case 3:
            if (*obj->p158 != obj->b15c) {
                obj->fn_63_2ED8(0, 0, 1, &obj->f164);
                if (obj->f64 < c[0])
                    obj->f64 *= c[2];
                obj->state = 4;
                return;
            }
            if (obj->b180 != *obj->p178) {
                obj->setVisibility(0);
                obj->state = 2;
                return;
            }
            if (c[0] == obj->timer) {
                switch (obj->b180) {
                case 0x0c:
                case 0x0f:
                    obj->setNodeVisibility(false, 0, ((int*)&obj->i184)[obj->b190], true, false);
                    if (obj->b190 == 0)
                        obj->b191 = 0;
                    if (obj->b190 == 2)
                        obj->b191 = 1;
                    switch (obj->b191) {
                    case 0:
                        obj->b190++;
                        break;
                    case 1:
                        obj->b190--;
                        break;
                    }
                    obj->setNodeVisibility(true, 0, ((int*)&obj->i184)[obj->b190], true, false);
                    obj->timer = c[1];
                    break;
                }
            }
            return;

        case 4:
            if (obj->getMotionFrame(0) >= obj->f164)
                obj->state = 0;
            return;
        }
    }
}
