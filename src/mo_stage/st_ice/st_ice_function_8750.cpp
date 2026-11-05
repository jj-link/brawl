#include <gr/ground.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

struct IceData {
    char pad[0x40];
    float acceleration;
    float maxSpeed;
    float angle;
    float damping;
    float wait;
    float resetSpeed;
};

namespace ice {

struct Stage_base { char pad[0x3c]; };

class Stage : public Stage_base {
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
    virtual void fn_62_258();
    virtual void fn_62_368();
    virtual void createObjPokeTrainer();
    virtual void fn_62_2A4C();
    virtual void fn_62_2A48();
    virtual void fn_62_2A3C();
    virtual void fn_62_2A34();
    virtual void fn_62_2A2C();
    virtual void fn_62_28A8();
    virtual void getItemGenPac();
    virtual void getItemPacEnemyFigure();
    virtual void getEnemyPac();
    virtual void getAdvRadarData();
    virtual void initializeStage();
    virtual void closeStage();
    virtual void renderDebugPositions();
    virtual void fn_62_360();
    virtual void process();
    virtual void updateStagePositions();
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
    virtual void fn_62_8654();
    virtual void fn_62_86BC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_62_8C6C();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_62_3114();
    virtual void startup();
    virtual void setNode();
    virtual void fn_62_A44();
    virtual IceData* fn_62_310C();

    char pad40[0x2c];
    unsigned char flags;
    char pad6d[0xe3];
    unsigned char state;
    char pad151[3];
    float timer;
    Matrix* matrix;
    float x;
    float y;
    float angle;
    float trigger;
    float speed;
    float direction;
    float acceleration;
    float maxSpeed;
    float amplitude;
    snd3DGenerator sound;

    const float& getAmplitude() const { return amplitude; }
};

}

extern "C" const float lbl_62_rodata_D8[];

extern "C" void fn_62_8750(ice::Ground* self, float dt) {
    const float* k = lbl_62_rodata_D8;

    if (!self->matrix)
        return;

    IceData* data = self->fn_62_310C();
    if (!data)
        return;

    Vec3f rotation;
    self->matrix->getRotate(&rotation);

    self->timer -= dt;
    if (self->timer <= k[0])
        self->timer = k[0];

    self->trigger -= dt;
    if (self->trigger < k[0])
        self->trigger = k[0];

    switch (self->state) {
    case 0:
        if (!reinterpret_cast< ::Ground* >(self)->m_isEnableCollisionStatus)
            reinterpret_cast< ::Ground* >(self)->setEnableCollisionStatus(true);

        self->speed = k[0];
        self->direction = k[1];
        self->acceleration = data->acceleration;
        self->maxSpeed = data->maxSpeed;
        self->amplitude = k[1];
        self->state = 1;
        break;

    case 1:
        if (k[0] == self->timer && k[0] != self->trigger) {
            self->trigger = k[0];
            reinterpret_cast< ::Ground* >(self)->setEnableCollisionStatus(false);
            self->sound.playSE((SndID)0x1c82, 0, 0, -1);
            self->state = 12;
        }
        break;

    case 12:
        self->speed += self->acceleration * self->direction;
        if (self->speed > self->maxSpeed)
            self->speed = self->maxSpeed;

        self->angle += self->speed;
        if (rotation.m_z + self->angle > k[3] + (data->angle - k[3])) {
            self->speed *= data->damping;
            self->direction *= k[4];
            self->amplitude *= data->damping;
            self->state = 13;
        }
        break;

    case 14:
        if (k[0] == self->timer)
            self->state = 15;

    case 13: {
        self->speed += self->direction * (self->acceleration * self->amplitude);

        if (nw4r::ut::Abs(self->speed) > self->maxSpeed * self->amplitude)
            self->speed = self->direction * (self->maxSpeed * self->amplitude);

        self->angle += self->speed;

        if ((self->direction > k[0] &&
             rotation.m_z + self->angle >
                 k[3] + (data->angle - k[3]) * self->getAmplitude()) ||
            (self->direction < k[0] &&
             rotation.m_z + self->angle <
                 k[3] - (data->angle - k[3]) * self->getAmplitude())) {
            self->speed *= data->damping;
            self->direction *= k[4];
            self->amplitude *= data->damping;

            if (self->amplitude < k[5] && self->state == 13) {
                self->timer = data->wait;
                self->state = 14;
            }
        }
        break;
    }

    case 15:
        self->angle -= data->resetSpeed;
        if (self->angle < k[0]) {
            self->angle = k[0];
            self->sound.playSE((SndID)0x1c83, 0, 0, -1);
            self->state = 0;
        }
        break;
    }
}
