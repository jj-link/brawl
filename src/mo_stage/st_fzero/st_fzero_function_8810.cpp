#pragma force_active on

typedef unsigned char u8;

extern "C" const float lbl_61_rodata_118;
extern "C" const float lbl_61_rodata_160;

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_61_8554();
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
    virtual void fn_61_84FC();
    virtual void fn_61_8558();
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
    virtual void fn_61_3A50();
    virtual void startup();
    virtual void fn_61_8BF4();
    virtual void fn_61_6D8();
    virtual void fn_61_3504();
    virtual void fn_61_3A4C();
    virtual void fn_61_2318();
    virtual void fn_61_3A44();
    virtual void fn_61_3A38();
    virtual void fn_61_3A28();
    virtual void fn_61_3A18();
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
    virtual void fn_61_3A14();
    virtual void fn_61_3A10();
    virtual void fn_61_3A08();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_61_3A00();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_61_3A7C();
    virtual void fn_61_3A74();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_61_3A6C();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_61_8810();
    virtual void fn_61_8AF8();
    virtual void fn_61_8D6C(u8, int, int, float*);

    char pad40[0x110];
    u8 state;
    char pad151[7];
    u8* input;
    char pad15c[4];
    float timer;
    u8* event;
    u8* output;
    u8 previous;
    char pad16d[0x4b];
    float frame;
};

extern "C" void fn_61_8810(Ground* self, float delta) {
    self->timer += delta;

    switch (self->state) {
    case 0:
        self->fn_61_8D6C(5, 0, 1, 0);
        self->state = 1;
    case 1:
        if (*self->event == 6) {
            unsigned int input = *self->input;
            int value;
            if (input == 0)
                value = 1;
            else if (input == 2)
                value = 2;
            else if (input == 3)
                value = 2;
            else if (input == 4)
                value = 3;
            else if (input == 5)
                value = 4;
            else
                value = input == 6 ? 0 : 5;

            bool valid = 0;
            if ((u8)value == 5)
                valid = 1;
            else if ((u8)value == self->previous)
                valid = 1;
            else if ((u8)value == 0) {
                if (self->timer < lbl_61_rodata_160 && self->previous == 4)
                    valid = 1;
            } else if (self->timer < lbl_61_rodata_160 &&
                       self->previous == (u8)(value - 1)) {
                valid = 1;
            }

            if (!valid) {
                *self->event = 7;
                self->state = 2;
            } else {
                *self->event = 8;
            }
        }
        break;

    case 2:
        if (*self->event == 7) {
            unsigned int input = *self->input;
            int value;
            if (input == 0)
                value = 1;
            else if (input == 2)
                value = 2;
            else if (input == 3)
                value = 2;
            else if (input == 4)
                value = 3;
            else if (input == 5)
                value = 4;
            else
                value = input == 6 ? 0 : 5;

            self->fn_61_8D6C(value, 0, 1, &self->frame);
            *self->output = value;
            self->previous = value;
            self->timer = lbl_61_rodata_118;
            self->state = 3;
        }
        break;

    case 3:
        if (self->getMotionFrame(0) >= self->frame) {
            self->fn_61_8D6C(5, 0, 1, 0);
            *self->output = 5;
            *self->event = 8;
            self->state = 1;
        }
        break;
    }
}
