#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" const char lbl_82_rodata_0[];

struct Object_vptr_3c_base {
    char pad[0x3c];
};

class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50(float (*)[4], unsigned long, unsigned long);
};

struct Config {
    float min;
    float max;
    float speed;
    float limit;
    float xlimit;
    float ylimit;
};

struct State {
    char pad0[0x1d8];
    Config* config;
    char pad1[4];
    Object_vptr_3c* object;
    char pad2[0xddc];
    float timer;
    float vx;
    float vy;
    float x;
    float y;
    float px;
    float py;
    char pad3[0x3c];
    snd3DGenerator generator;
    unsigned long node;
    int sound;
};

extern "C" void fn_82_3374(State* self, float dt) {
    const float* c = (const float*)lbl_82_rodata_0;

    if (self->timer <= c[4]) {
        float range = self->config->max - self->config->min;
        self->timer = self->config->min + range * randf();
        self->vx = self->config->speed * (c[8] - c[18] * randf());
        self->vy = self->config->speed * (c[8] - c[18] * randf());
    }

    self->timer -= dt;
    self->x = self->vx * dt + self->x;

    float limit = self->config->limit;
    float difference = limit - self->x;
    float negativeLimit = -limit;
    float a = nw4r::math::FSelect(difference, self->x, limit);
    self->x = nw4r::math::FSelect(negativeLimit - a, negativeLimit, a);

    self->y += self->vy * dt;
    limit = self->config->limit;
    difference = limit - self->y;
    negativeLimit = -limit;
    a = nw4r::math::FSelect(difference, self->y, limit);
    self->px += self->x * dt;
    self->y = nw4r::math::FSelect(negativeLimit - a, negativeLimit, a);
    self->py += self->y * dt;

    if (self->px > self->config->xlimit)
        self->vx = -self->config->speed;
    else if (self->px < -self->config->xlimit)
        self->vx = self->config->speed;

    if (self->py > self->config->ylimit)
        self->vy = -self->config->speed;
    else if (self->py < -self->config->ylimit)
        self->vy = self->config->speed;

    float matrix[3][4];
    self->object->slot50(matrix, 0, self->node);

    float z = matrix[2][3];
    float y = matrix[1][3];
    float x = matrix[0][3];
    Vec3f pos;
    pos.m_y = y;
    pos.m_x = x;
    pos.m_z = z;
    self->generator.setPos(&pos);

    if (!self->sound)
        self->sound = self->generator.playSE((SndID)0x1dc2, -1, 0, -1);
}
