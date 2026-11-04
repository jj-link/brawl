#include <ec/ec_mgr.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <snd/snd_3d_generator.h>

#pragma force_active on

struct IceParameters {
    char pad[0x9c];
    float distance6;
    float distance7;
    float acceleration;
    float maxSpeed;
    float minDelay;
    float maxDelay;
    float returnSpeed;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_62_3710();
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
    virtual void fn_62_3680();
    virtual void fn_62_373C();
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
    virtual void fn_62_3114();
    virtual void startup();
    virtual void fn_62_4484();
    virtual void fn_62_A44();
    virtual IceParameters* fn_62_310C();
    virtual void fn_62_3108();
    virtual void fn_62_2C7C();
    virtual void fn_62_3100();
    virtual void fn_62_30F4();
    virtual void fn_62_30E4();
    virtual void fn_62_30D4();
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
    virtual void fn_62_30D0();
    virtual void fn_62_30CC();
    virtual void fn_62_30C4();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_62_30BC();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_62_3140();
    virtual void fn_62_3138();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_62_3130();
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
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_62_39B0();
    virtual void fn_62_3A80();
    virtual void fn_62_3AD8();
    virtual void fn_62_4190();
    virtual void fn_62_43BC();
    virtual void fn_62_45AC();
    virtual void fn_62_4988();
    virtual void fn_62_4B04(float, float);
    virtual void fn_62_4B1C(int);

    char pad40[4];
    nw4r::g3d::ScnMdl** model;
    char pad48[0x108];
    unsigned char state;
    char pad151[3];
    float timer;
    char pad158[0x0c];
    unsigned char* mode;
    unsigned char* event;
    unsigned char previousMode;
    char pad16d[3];
    float speed;
    float distance;
    float field178;
    float position;
    float field180;
    char pad184[0x31];
    unsigned char field1b5;
    char pad1b6[6];
    snd3DGenerator sound;
    int soundHandle1;
    int soundHandle2;
    unsigned char field1cc;
    char pad1cd[3];
    float field1d0;
};

extern "C" {
extern const float lbl_62_rodata_80[];
extern const char lbl_62_data_DC0[];

void cmReqQuake__FiP5Vec3f(int, Vec3f*);
void cmRemoveQuake__Fi(int);
float randf__Fv();

void fn_62_3AD8(Ground* self, float dt) {
    const float* k = lbl_62_rodata_80;
    IceParameters* params = self->fn_62_310C();

    if (params != 0) {
        self->timer -= dt;
        if (self->timer < k[0])
            self->timer = k[0];

        if (*self->mode != self->previousMode)
            self->state = 0;

        switch (*self->mode) {
        case 1:
            switch (self->state) {
            case 0:
                self->disableAttack(0);
                self->field1b5 = 0;
                self->fn_62_4B04(k[1], k[1]);
                self->state = 3;
                break;
            case 3:
                if (self->getMotionFrame(0) >= k[2]) {
                    self->sound.playSE((SndID)0x1c7c, 0, 0, -1);
                    Vec3f quake(k[0], k[0], k[0]);
                    cmReqQuake__FiP5Vec3f(1, &quake);
                    self->state = 1;
                }
                break;
            }
            break;

        case 2:
            switch (self->state) {
            case 0: {
                unsigned long effect = g_ecMgr->setEffect((EfID)0x480001);
                g_ecMgr->setParent(effect, *self->model, lbl_62_data_DC0, false);
                cmRemoveQuake__Fi(1);
                Vec3f quake(k[0], k[0], k[0]);
                cmReqQuake__FiP5Vec3f(3, &quake);
                self->sound.playSE((SndID)0x1c7d, 0, 0, -1);
                self->fn_62_4988();
                self->field1cc = 2;
                self->field1d0 = k[3];
                self->state = 2;
                break;
            }
            case 1:
                break;
            case 2:
                if (self->getMotionFrame(0) >= k[4]) {
                    self->soundHandle1 =
                        self->sound.playSE((SndID)0x1c7e, 0, 0, -1);
                    Vec3f quake(k[0], k[0], k[0]);
                    cmReqQuake__FiP5Vec3f(1, &quake);
                    self->fn_62_4B04(k[5], k[5]);
                    self->state = 1;
                }
                break;
            }
            break;

        case 3:
            switch (self->state) {
            case 0:
                if (self->soundHandle1 != -1) {
                    self->sound.stopSE(self->soundHandle1, 30);
                    self->soundHandle1 = -1;
                }
                self->sound.playSE((SndID)0x1c7f, 0, 0, -1);
                self->soundHandle2 =
                    self->sound.playSE((SndID)0x1c84, 0, 0, -1);
                cmRemoveQuake__Fi(1);
                {
                    Vec3f quake(k[0], k[0], k[0]);
                    cmReqQuake__FiP5Vec3f(5, &quake);
                }
                self->fn_62_4B04(k[1], k[1]);
                self->disableAttack(0);
                self->field1b5 = 0;
                self->distance = k[0];
                self->speed = k[0];
                self->field178 = k[0];
                self->position = k[0];
                self->field180 = k[0];
                self->state = 1;
                break;

            case 1:
                if (*self->event == 6) {
                    self->distance = params->distance6;
                    self->sound.playSE((SndID)0x1c88, 0, 0, -1);
                    self->state = 16;
                }
                if (*self->event == 7) {
                    self->distance = params->distance7;
                    self->sound.playSE((SndID)0x1c88, 0, 0, -1);
                    self->state = 16;
                }
                break;

            case 16:
                self->speed += params->acceleration * dt;
                if (self->speed > params->maxSpeed)
                    self->speed = params->maxSpeed;
                self->position -= self->speed;
                if (nw4r::ut::Abs(self->position) > self->distance) {
                    self->fn_62_4B1C(10);
                    float r = randf__Fv();
                    float range = params->maxDelay - params->minDelay;
                    self->timer = params->minDelay + range * r;
                    self->state = 17;
                }
                break;

            case 17:
                if (k[0] == self->timer || *self->mode == 4)
                    self->state = 18;
                break;

            case 18:
                self->position += params->returnSpeed * dt;
                if (self->position >= k[0]) {
                    self->distance = k[0];
                    self->speed = k[0];
                    self->field178 = k[0];
                    self->position = k[0];
                    self->field180 = k[0];
                    if (*self->event != 0)
                        *self->event = 5;
                    self->fn_62_4B1C(14);
                    self->state = 1;
                }
                break;
            }
            break;

        case 4:
            switch (self->state) {
            case 0:
                self->disableAttack(0);
                self->field1b5 = 0;
                if (self->soundHandle2 != -1) {
                    self->sound.stopSE(self->soundHandle2, 30);
                    self->soundHandle2 = -1;
                }
                self->sound.playSE((SndID)0x1c8d, 0, 0, -1);
                {
                    Vec3f quake(k[0], k[0], k[0]);
                    cmReqQuake__FiP5Vec3f(4, &quake);
                }
                self->fn_62_4B04(k[6], k[6]);
                self->fn_62_4B1C(14);
                self->field1cc = 4;
                self->field1d0 = k[7];
                self->state = 1;
                /* fall through */
            case 1:
                self->position += params->returnSpeed * dt;
                if (self->position >= k[0]) {
                    self->distance = k[0];
                    self->speed = k[0];
                    self->field178 = k[0];
                    self->position = k[0];
                    self->field180 = k[0];
                    self->state = 4;
                }
                break;
            }
            break;
        }

        self->previousMode = *self->mode;
    }
}
}
