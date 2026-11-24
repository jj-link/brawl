#include <types.h>
#include <ai/ai_mgr.h>
#include <mt/mt_prng.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on

#pragma pool_data on
#pragma pool_fp_consts on

struct AIPlatform {
    char pad00[0x18];
    float left;
    char pad1k010;
    float right;
    char pad24[8];
    float height;
    char pad30[0xD];
    signed char direction;
};

struct AIFighter {
    char pad00[0x50];
    unsigned int flags;
    char pad54[8];
    Vec2f position;
    char pad64[0x1C];
    float vx;
    float vy;
    char pad88[0x18];
    float direction;
    char padA4[0x18];
    AIPlatform* platform;
    unsigned char platformState;
    char padC1[7];
    int platformIndex;
    char padCC[0xE0];
    int action;
};

struct AIPath {
    char pad00[0xDC];
    float direction;
    char padE0[0x18];
    char query[1];
};

struct AIInput {
    char pad00[0x42];
    signed char fighterId;
    char pad43;
    AIPath* path;
    char pad48[8];
    int state;
    int timer;
    char pad58[0x40];
    signed char level;
    char pad99[0x77];
    signed char targetId;
};

extern "C" {

AIFighter* fn_27_1F1F58(signed char*);
void fn_27_1F9FBC(AIInput*, int, signed char*, unsigned int, int);
signed char fn_27_1FE1C0(AIInput*, float*, int);
int fn_27_20B568(AIFighter*);
float fn_27_20BCBC(AIFighter*, Vec2f*, float);
AIPlatform* fn_27_1EEA1C(aiMgr*, void*);
AIPlatform* fn_27_1EF888(aiMgr*, AIPlatform*, Vec2f*, AIPlatform*, int,
                         float, float, float);
AIPlatform* fn_27_1EEAA8(aiMgr*, AIPlatform*, float, AIPlatform*, int,
                         const Vec2f*, int, float, float, AIPlatform**, float);
int fn_27_1EFE3C(aiMgr*, AIPlatform*, AIPlatform*, float, float, float, int);
void fn_27_21062C(AIPath*, AIPlatform*, AIPlatform*, float, float);

int fn_27_2056D0(AIInput* self, Vec2f* stick, u32* buttons)
{
    f32 k000 = 0.0f, k004 = 50.0f, k008 = 0.6f, k00c = -0.6f;
    f32 k010 = 10.0f, k014 = 1.5f, k018 = 0.1f, k01c = 30.0f;
    f32 k020 = 1.0f, k024 = 5.0f, k028 = 0.009999999776482582f, k02c = 90.0f;
    f32 k030 = 0.25f, k034 = 0.699999988079071f, k038 = 70.0f, k03c = 0.375f;
    f32 k040 = 100.0f, k044 = 20.0f, k048 = 15.0f, k04c = 0.5f;
    f32 k050 = 0.05000000074505806f, k054 = 4.0f, k058 = 998001.0f, k05c = 500.0f;
    f32 k060 = 12.0f, k064 = 0.8999999761581421f, k068 = 0.20000000298023224f, k06c = 400.0f;
    f32 k070 = 0.11874999850988388f, k074 = 80.0f, k078 = 120.0f, k07c = 0.015625f;
    f32 k080 = 0.30000001192092896f;
    f64 d088 = 5.0, d090 = 0.01;
    f32 k098 = -10.0f, k09c = 0.4000000059604645f, k0a0 = 0.9900000095367432f, k0a4 = 0.75f;
    f32 k0a8 = 0.800000011920929f, k0ac = 0.3499999940395355f, k0b0 = 0.949999988079071f, k0b4 = 0.007000000216066837f;
    f32 k0b8 = 2.0f, k0bc = 40.0f, k0c0 = 0.3199999928474426f, k0c4 = 3.0f;
    f32 k0c8 = 0.15000000596046448f, k0cc = 0.550000011920929f, k0d0 = 6.0f, k0d4 = 8.0f;
    f32 k0d8 = -20.0f, k0dc = 200.0f, k0e0 = 25.0f, k0e4 = 96.0f;
    f32 k0e8 = 0.004166666883975267f, k0ec = -0.5f, k0f0 = 1.2999999523162842f, k0f4 = -50.0f;
    f32 k0f8 = 0.03999999910593033f, k0fc = -1.0f, k100 = -0.10000000149011612f, k104 = 0.125f;
    f32 k108 = 0.02857142873108387f, k10c = 0.03750000149011612f, k110 = 0.015000000596046448f, k114 = 2500.0f;
    f32 k118 = 60.0f, k11c = 0.02199999988079071f, k120 = 0.00800000037997961f, k124 = -5.0f;
    f32 k128 = 0.014999999664723873f, k12c = -40.0f, k130 = 35.0f, k134 = -4.0f;
    f32 k138 = 0.00699999975040555f, k13c = 32.0f, k140 = 256.0f, k144 = 128.0f;
    f32 k148 = 28.0f, k14c = 0.00390625f, k150 = 0.0009765625f;
    f64 d158 = 4503601774854144.0, d160 = 4503599627370496.0;
    f32 k168 = 7.0f, k16c = 1.1754943508222875e-38f, k170 = -9.999999747378752e-06f, k174 = 0.0625f;
    f32 k178 = 150.0f, k17c = 0.0078125f;
    f64 d180 = 2.0, d188 = 2.5;
    f32 k190 = 1.100000023841858f, k194 = 1.2000000476837158f, k198 = -9999.900390625f, k19c = 0.0833333358168602f;
    f32 k1a0 = -0.30000001192092896f, k1a4 = 26.0f, k1a8 = 9999979520.0f, k1ac = 900.0f;
    f32 k1b0 = 10000.0f;
    f64 d1b8 = 1.0, d1c0 = 1.5;
    f32 k1c8 = 1600.0f, k1cc = 0.004999999888241291f, k1d0 = 0.019999999552965164f, k1d4 = 0.001500000013038516f;
    f32 k1d8 = 0.008999999612569809f, k1dc = 55.0f, k1e0 = 0.0010000000474974513f, k1e4 = 0.012000000104308128f;
    f32 k1e8 = -5000.0f, k1ec = -2000.0f, k1f0 = 0.03125f, k1f4 = 99999.8984375f;
    f32 k1f8 = 1000.0f, k1fc = -80.0f, k200 = -90.0f, k204 = 0.003000000026077032f;
    f32 k208 = 0.8500000238418579f, k20c = 0.002199999988079071f, k210 = 0.44999998807907104f, k214 = 0.7250000238418579f;
    f32 k218 = -1.2999999523162842f, k21c = 0.009499999694526196f, k220 = 9.999999747378752e-05f, k224 = 11.0f;
    f32 k228 = -0.4000000059604645f, k22c = 0.05999999865889549f, k230 = 0.10999999940395355f, k234 = 1.7999999523162842f;
    f32 k238 = -30.0f, k23c = -0.699999988079071f, k240 = 0.4712389409542084f, k244 = 1.4137167930603027f;
    f32 k248 = 1.0610328912734985f, k24c = 22.0f, k250 = -8.0f, k254 = 3.1415927410125732f;
    f32 k258 = 0.029999999329447746f, k25c = -6.0f, k260 = -0.800000011920929f, k264 = 58.0f;
    f32 k268 = 2.5f, k26c = -180.0f;
    AIFighter* fighter = fn_27_1F1F58(&self->fighterId);

    if (!(fighter->flags & 0x1000)) {
        signed char id = -1;
        fn_27_1F9FBC(self, 1, &id, 0, 0);
        return 1;
    }

    if (fighter->flags & 0x2000) {
        float square;
        float level = self->level;
        if (level >= 40.0f && !(self->timer & 1)) {
            if (fn_27_20B568(fighter) != 0) {
                square = fighter->vx * fighter->vx + fighter->vy * fighter->vy;
                float length;
                if ((float)(double)nw4r::ut::Abs(square) <= 1.1754943508222875e-38f)
                    length = 0.0f;
                else
                    length = square * rsqrtf(square);
                if (!(length > 2.5f))
                    goto skipPress;
            }
            if (randf() < 0.009999999776482582f * (level - 35.0f)) {
                *buttons |= soController::getButtonMask(soController::Pad_Button_Attack);
                *buttons |= soController::getButtonMask(soController::Pad_Button_Guard);
            }
        }
    }

skipPress:
    switch (self->state) {
    case 0: {
        self->targetId = fn_27_1FE1C0(self, 0, 0);
        float value = -180.0f * randf();
        self->state++;
        self->timer = (int)value - 60;
    }
    case 1: {
        AIFighter* target = fn_27_1F1F58(&self->targetId);
        AIPlatform* destination = target->platform;

        if (fighter->flags & 0x100) {
            self->path->direction = target->position.m_x > fighter->position.m_x ? 1.0f : -1.0f;
            if (destination != fighter->platform) {
                float distance = fighter->action == 0x1B ? 80.0f : 20.0f;
                destination = fn_27_1EF888(g_aiMgr, fighter->platform, &fighter->position,
                                           destination, fighter->platformIndex,
                                           distance, 20.0f, 0.5f);
                if (destination == fighter->platform)
                    destination = target->platform;
                else if (destination != target->platform)
                    self->path->direction = destination->direction;
            }
            fn_27_21062C(self->path, destination, target->platform, 0.0f, 0.0f);
        } else {
            self->path->direction = target->position.m_x > fighter->position.m_x ? -1.0f : 1.0f;
            if (destination == fighter->platform) {
                Vec2f pos(fighter->position.m_x, fighter->position.m_y);
                float distance = fighter->action == 0x1B ? 80.0f : 20.0f;
                destination = fn_27_1EEAA8(g_aiMgr, fighter->platform, fighter->position.m_x, 0,
                                           fighter->platformIndex, &pos, 1,
                                           distance, 20.0f, 0, 0.25f);
                if (destination != fighter->platform)
                    self->path->direction = destination->direction;
            }
            fn_27_21062C(self->path, destination, 0, 0.0f, 0.0f);
        }
        self->state++;
        break;
    }
    }

    AIPlatform* destination = fn_27_1EEA1C(g_aiMgr, self->path->query);
    AIFighter* target = fn_27_1F1F58(&self->targetId);
    if (!destination) {
        self->state = 0;
    } else {
        float distance = 99999.8984375f;
        float direction;
        if (target->platform == fighter->platform) {
            direction = target->position.m_x > fighter->position.m_x ? 1.0f : -1.0f;
            distance = direction * (target->position.m_x - fighter->position.m_x);
            if (!(fighter->flags & 0x100)) {
                if (self->level < 50)
                    direction = -direction;
                else if (0.5f * (fighter->platform->left + fighter->platform->right) > fighter->position.m_x)
                    direction = 1.0f;
                else
                    direction = -1.0f;
            }
        } else if (destination != fighter->platform || fighter->platformState == 2) {
            direction = self->path->direction;
        } else {
            direction = 0.0f;
        }

        if (fighter->flags & 1) {
            if (fighter->action == 0x1B && fighter->vy <= 0.0f &&
                (fn_27_20B568(fighter) == 0 || destination != fighter->platform ||
                 fighter->platformState == 2) && !(self->timer & 7)) {
                *buttons |= soController::getButtonMask(soController::Pad_Button_Attack);
            }
        } else {
            float dy = target->position.m_y - fighter->position.m_y;
            if (dy > 10.0f && dy < 50.0f && self->state == 2)
                self->state = 3;
        }

        if (fn_27_20B568(fighter) == 0) {
            if (0.5f * (fighter->platform->left + fighter->platform->right) > fighter->position.m_x)
                direction = 1.0f;
            else
                direction = -1.0f;
        } else {
            float edge = fn_27_20BCBC(fighter, &fighter->position, direction);
            if (fighter->flags & 0x100) {
                if (edge < 10.0f && target->platform == fighter->platform) {
                    if (0.5f * (fighter->platform->left + fighter->platform->right) > fighter->position.m_x)
                        direction = 1.0f;
                    else
                        direction = -1.0f;
                } else if (fighter->direction * direction > 0.0f) {
                    if (distance < 10.0f)
                        goto skipDirection;
                    if (edge < 10.0f) {
                        if (!fn_27_1EFE3C(g_aiMgr, fighter->platform, destination,
                                          fighter->position.m_x,
                                          fighter->action == 0x1B ? 80.0f : 20.0f,
                                          20.0f, fighter->platformIndex))
                            goto skipDirection;
                        if (!(fighter->flags & 1) &&
                            fighter->position.m_y < 10.0f + destination->height &&
                            self->state == 2)
                            self->state = 3;
                    }
                }
            } else if (edge < 10.0f) {
                if (0.5f * (fighter->platform->left + fighter->platform->right) > fighter->position.m_x)
                    direction = 1.0f;
                else
                    direction = -1.0f;
            }
        }

        stick->m_x = direction;

skipDirection:
        if (self->state >= 3) {
            if (self->state > 3)
                stick->m_y = 1.0f;
            self->state++;
            if (self->state > 12)
                self->state = 2;
        } else if (!(fighter->flags & 1) && destination == fighter->platform &&
                   destination != target->platform) {
            self->state = 1;
        }

        if (self->timer > 0)
            self->state = 0;
    }

    return 1;
}
}
