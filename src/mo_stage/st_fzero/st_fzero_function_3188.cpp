#include <mt/mt_vector.h>
#include <snd/snd_system.h>
#include <st/se_util.h>
#pragma force_active on

struct Data { unsigned char pad[4]; float duration; };
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
    virtual void fn_61_30A0();
    virtual void fn_61_3114();
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
    virtual void fn_61_3A50();
    virtual void startup();
    virtual void setNode();
    virtual void fn_61_6D8();
    virtual Data* fn_61_3504();
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
    virtual void fn_61_3188();
    virtual void fn_61_350C();
    virtual void fn_61_35B8(int, int, bool, float*);
    unsigned char pad40[0x2c];
    unsigned char flags;
    unsigned char pad6d[0xe3];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* trigger;
    unsigned char pad15c[0xc];
    unsigned char ready;
    unsigned char phase;
    unsigned char pad16a[2];
    float previous;
    float end;
    unsigned char sound[0x20];
};
extern "C" {
extern const float lbl_61_rodata_30;
void fn_61_3188(Ground* self, float delta) {
    Data* data = self->fn_61_3504();
    if (data) {
        self->timer -= delta;
        if (self->timer < lbl_61_rodata_30)
            self->timer = lbl_61_rodata_30;
        switch (self->state) {
        case 0:
            self->fn_61_35B8(3, 0, true, 0);
            self->setVisibility(0);
            self->state = 1;
        case 1:
            if (*self->trigger == 4) {
                self->fn_61_35B8(0, 0, true, &self->end);
                self->ready = 0;
                g_sndSystem->playSE((SndID)0x1c70, 0, 0, 0, -1);
                self->timer = data->duration;
                self->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            if (!((self->flags >> 7) & 1))
                self->setVisibility(1);
            switch (self->phase) {
            case 0:
                if (self->getMotionFrame(0) >= self->end) {
                    self->fn_61_35B8(1, 1, true, &self->end);
                    self->previous = lbl_61_rodata_30;
                    ((StSeUtil::SeSeq*)self->sound)->playFrame(0, self->getMotionFrame(0), lbl_61_rodata_30);
                }
                break;
            case 1:
                ((StSeUtil::SeSeq*)self->sound)->playFrame(0, self->getMotionFrame(0));
                if (lbl_61_rodata_30 == self->timer)
                    self->ready = 1;
                if (self->getMotionFrame(0) < self->previous) {
                    if (self->ready == 1) {
                        self->fn_61_35B8(2, 0, true, &self->end);
                        g_sndSystem->playSE((SndID)0x1c72, 0, 0, 0, -1);
                    } else {
                        self->previous = self->getMotionFrame(0);
                    }
                } else {
                    self->previous = self->getMotionFrame(0);
                }
                break;
            case 2:
                if (self->getMotionFrame(0) >= self->end) {
                    self->fn_61_35B8(3, 0, true, 0);
                    self->state = 0;
                }
                break;
            }
            break;
        }
    }
}
}
