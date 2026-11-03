#pragma force_active on

#include <gr/ground.h>
#include <snd/snd_3d_generator.h>

extern "C" {
extern const float lbl_54_rodata_C8[];
}

struct Params {
    char pad[0x48];
    float time1;
    char pad4c[0x10];
    float time2;
};

struct Base {
    char pad[0x3c];
};

struct Obj : Base {
#define V(n) virtual void vf##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26)
    virtual void setVis(unsigned long);
    V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37)
    V(38) V(39)
    virtual Params* active();
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60)
    V(61) V(62) V(63) V(64) V(65) V(66)
    virtual float getFrame(unsigned long);
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97)
    V(98) V(99) V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    V(108) V(109) V(110) V(111) V(112) V(113) V(114) V(115) V(116)
    virtual void setMotion(int, int, int, float*);
#undef V

    char pad40[0x110];
    unsigned char state;
    char pad151[3];
    float timer;
    unsigned char* trigger;
    Vec3f* positions;
    char pad160[4];
    unsigned char* index;
    unsigned char* output;
    char pad16c[0x14];
    float value;
    char pad184[4];
    float end;
    snd3DGenerator sound;
    char pad194[8];
    unsigned int flags : 3;
    unsigned int rest : 29;
};

extern "C" void fn_54_B874(Obj* self, float delta) {
    const float* constants = lbl_54_rodata_C8;
    Params* param = self->active();
    if (param) {
        self->timer -= delta;
        if (self->timer < constants[1])
            self->timer = constants[1];

        switch (self->state) {
        case 0:
            self->setMotion(1, 0, 1, 0);
            self->setVis(0);
            ((Ground*)self)->setEnableCollisionStatus(false);
            *self->output = 4;
            self->state = 1;
            break;

        case 1:
            if (*self->trigger == 4) {
                self->timer = param->time1;
                self->value = constants[0];
                self->state = 12;
            }
            break;

        case 12:
            if (constants[1] == self->timer) {
                self->setVis(1);
                ((Ground*)self)->setEnableCollisionStatus(true);
                *self->output = 5;
                self->sound.playSE((SndID)0x1bca, 0, 0, -1);
                self->sound.setPos(&self->positions[*self->index]);
                self->flags = 0;
                self->state = 7;
            }
            break;

        case 7:
            self->value += constants[7] * delta;
            if (self->value >= constants[8])
                self->value = constants[8];
            if (*self->trigger != 4) {
                self->timer = param->time2;
                self->state = 9;
            }
            break;

        case 9:
            if (constants[1] == self->timer) {
                self->setMotion(0, 0, 1, &self->end);
                ((Ground*)self)->setEnableCollisionStatus(false);
                *self->output = 4;
                self->sound.playSE((SndID)0x1bcb, 0, 0, -1);
                self->sound.setPos(&self->positions[*self->index]);
                self->flags = 1;
                self->state = 10;
            }
            break;

        case 10:
            if (self->getFrame(0) >= self->end)
                self->state = 0;
            break;
        }
    }
}
