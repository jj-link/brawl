#include <mt/mt_vector.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>

#pragma force_active on

struct Data {
    char pad[0x3c];
    float value;
};

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
    virtual void fn_50_89C0();
    virtual void fn_50_8A60();
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
    virtual void fn_50_2324();
    virtual void startup();
    virtual void setNode();
    virtual void fn_50_690();
    virtual Data* fn_50_231C();
    virtual void fn_50_2318();
    virtual void fn_50_1F70();
    virtual void fn_50_2310();
    virtual void fn_50_2304();
    virtual void fn_50_22F4();
    virtual void fn_50_22E4();
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
    virtual void fn_50_22E0();
    virtual void fn_50_22DC();
    virtual void fn_50_22D4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_50_22CC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_50_182C();
    virtual void fn_50_2348();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_50_2340();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
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
    virtual void fn_50_20F4();
    virtual void fn_50_8E78();
    virtual void fn_50_8AF8();
    virtual void fn_50_8BD8();
    virtual void fn_50_8F5C();
    virtual void fn_50_92F8();
    virtual void fn_50_9528();
    virtual void fn_50_93AC();
    virtual void fn_50_96B0(int, int, int, float*);
};

struct Object : Ground {
    char pad40[0x2c];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x14];
    float value16c;
    char pad170[9];
    unsigned char flag179;
    char pad17a[6];
    unsigned char* status;
    char pad184[8];
    float endFrame;
    snd3DGenerator sound;
    int handle1;
    int handle2;
    char seq[0x20];
};

extern "C" const float lbl_50_rodata_100[];
extern "C" float randf__Fv();

extern "C" void fn_50_8BD8(Object* self, float delta) {
    const float* c = lbl_50_rodata_100;
    Data* data = self->fn_50_231C();

    if (data != 0) {
        float t = self->timer - delta;
        self->timer = t;
        if (t < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            self->fn_50_96B0(1, 0, 1, 0);
            self->setVisibility(0);
            self->disableAttack(0);
            self->flag179 = 0;
            self->state = 1;
        case 1:
            if (*self->status == 3) {
                self->fn_50_96B0(0, 0, 1, &self->endFrame);
                float r = randf__Fv();
                float v = c[6];
                v = v * data->value;
                r = v * r;
                self->value16c = -data->value + r;
                ((StSeUtil::SeSeq*)self->seq)->playFrame(
                    0, self->getMotionFrame(0), c[0]);
                self->handle2 = -1;
                self->state = 7;
            }
            break;
        case 7:
            if (!((self->flags >> 7) & 1))
                self->setVisibility(1);

            if (self->getMotionFrame(0) >= self->endFrame) {
                *self->status = 6;
                self->state = 0;
            } else if (self->getMotionFrame(0) > c[7]) {
                if (self->handle1 != -1) {
                    self->sound.stopSE(self->handle1, 5);
                    self->handle1 = -1;
                }
                if (self->handle2 == -1)
                    self->handle2 = self->sound.playSE(
                        (SndID)0x1b88, 0, 0, -1);
            } else {
                ((StSeUtil::SeSeq*)self->seq)->playFrame(
                    0, self->getMotionFrame(0));
            }
            break;
        }
    }
}
