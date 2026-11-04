#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on

struct Data { char pad[0x10]; unsigned char a, b; };
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
    virtual void fn_78_7D58();
    virtual void fn_78_7DC4();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_78_8978();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_78_26A4();
    virtual void startup();
    virtual void setNode();
    virtual void fn_78_58C();
    virtual Data* fn_78_1C40();
    virtual void fn_78_26A0();
    virtual void fn_78_1760();
    virtual void fn_78_2698();
    virtual void fn_78_268C();
    virtual void fn_78_267C();
    virtual void fn_78_266C();
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
    virtual void fn_78_2668();
    virtual void fn_78_2664();
    virtual void fn_78_265C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_78_2654();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_78_26D0();
    virtual void fn_78_26C8();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_78_26C0();
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
    virtual void fn_78_670();
    virtual void fn_78_7E48();
    virtual void fn_78_8274();
    virtual void fn_78_8530(int, int, bool, float*);
    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[4];
    unsigned char *phase, *count, *trigger;
    unsigned char visible, blink;
    char pad16a[2];
    float endFrame;
    char sound[0x20];
};
extern "C" {
void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern const float lbl_78_rodata_E8;
extern const float lbl_78_rodata_F4;
void fn_78_7E48(Ground* self, float delta) {
    Data* data = self->fn_78_1C40();
    if (data) {
        switch (self->state) {
        case 0:
            self->fn_78_8530(5, 0, true, 0);
            setEnableCollisionStatus__6GroundFb(self, true);
            self->setVisibility(1);
            *self->phase = 0;
            *self->count = data->a;
            self->state = 1;
        case 1:
            if (*self->trigger == 1) {
                switch (*self->phase) {
                case 0: self->fn_78_8530(0, 0, true, &self->endFrame); break;
                case 1: self->fn_78_8530(2, 0, true, &self->endFrame); break;
                case 2: self->fn_78_8530(3, 0, true, &self->endFrame); break;
                case 3:
                    self->fn_78_8530(4, 0, true, &self->endFrame);
                    setEnableCollisionStatus__6GroundFb(self, false);
                    ((StSeUtil::SeSeq*)self->sound)->playFrame(0, self->getMotionFrame(0), lbl_78_rodata_E8);
                    break;
                }
                self->state = 2;
            }
            break;
        case 2:
            if (*self->phase == 3)
                ((StSeUtil::SeSeq*)self->sound)->playFrame(0, self->getMotionFrame(0));
            if (self->getMotionFrame(0) >= self->endFrame) {
                *self->trigger = 0;
                switch (*self->phase) {
                case 0: self->state = 1; break;
                case 1:
                    *self->count = data->b - data->a;
                    ++*self->phase;
                    self->state = 1;
                    break;
                case 2: self->state = 1; break;
                case 3: *self->phase = 10; self->state = 7; break;
                }
            }
            break;
        case 7:
            if (*self->phase == 100) {
                self->fn_78_8530(5, 0, true, 0);
                self->visible = 0;
                self->blink = 1;
                self->timer = lbl_78_rodata_F4;
                self->state = 8;
            }
            break;
        case 8:
            self->blink--;
            if (self->visible == 0) {
                if ((signed char)self->blink < 0) {
                    self->setVisibility(1);
                    self->visible = 1;
                    self->blink = 1;
                }
            } else if ((signed char)self->blink < 0) {
                self->setVisibility(0);
                self->visible = 0;
                self->blink = 1;
            }
            self->timer -= delta;
            if (self->timer < lbl_78_rodata_E8)
                self->timer = lbl_78_rodata_E8;
            if (lbl_78_rodata_E8 == self->timer)
                self->state = 0;
            break;
        }
    }
}
}