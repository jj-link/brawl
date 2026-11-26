#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on
#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>

struct AiScript {
    u8 pad0[0x78];
    u16 action;
};

struct AiFighterState {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[8];
    Vec2f vector5C;
    u8 pad64[0x14];
    f32 unk78;
    u8 pad7C[8];
    f32 unk84;
    u8 pad88[0x18];
    f32 unkA0;
    u8 padA4[8];
    s32 unkAC;
    u8 padB0[0x1C];
    s32 unkCC;
};

struct AiInput {
    u8 pad0[0x42];
    s8 fighterId;
    u8 pad43;
    AiScript* script;
    u8 pad48[8];
    s32 unk50;
    s32 unk54;
    u8 pad58[0xC];
    u8 unk64;
    u8 pad65[0xB];
    s32 unk70;
    u8 pad74[0x24];
    u8 level;
    u8 pad99[0x77];
    s8 targetId;
};

extern "C" {
AiFighterState* fn_27_1F1F58(s8* fighterId);
void fn_27_1F9FBC(AiInput* self, s32 mode, s8* fighterId, u32 script, s32 argument);
void fn_27_1FD190(AiInput* self);
void fn_27_20DB40(AiScript* script, u32 action, s8* fighterId, u32 arg, u32 arg2);
s32 fn_27_20B63C(AiFighterState*);
s32 fn_27_20B668(AiFighterState*);
f32 fn_27_20BCBC(AiFighterState*, Vec2f*, f32);
}

union Id {
    s8 v;
    s32 w;
};

union Counter {
    s32 value;
    u32 bits;
};

static inline void finish(AiInput* self, u32* buttons) {
    *buttons = soController::getButtonMask((soController::PadButton)1);
    self->unk50 = 0x14;
    self->unk54 = 0;
}

extern "C" s32 fn_27_2051AC(AiInput* self, Vec2f* stick, u32* buttons) {
    u8 lvA;
    s32 left;
    u8 lvB;
    s32 right;
    s32 i;
    Id id24;
    Id id20;
    Id id1C;
    Id id18;
    Id id14;
    Id id10;
    Id idC;
    Id id8;
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
    AiFighterState* fs = fn_27_1F1F58(&self->fighterId);

    if (!(fs->unk50 & 0xC00)) {
        id24.v = -1;
        fn_27_1F9FBC(self, 1, &id24.v, 0, 0);
        return 1;
    }
    if (self->unk50 < 0x14 && (fs->unk50 & 0x800)) {
        self->unk50 = 0x14;
    }

    if (self->unk50 < 0xa) {
        switch (self->unk50) {
        case 0:
            if (fn_27_20B63C(fs) != 0 || fn_27_20B668(fs) != 0) {
                switch (fs->unkAC) {
                case 0x12:
                    self->unk70 = 0;
                    break;
                }
                finish(self, buttons);
                return 1;
            }
            break;
        }
    } else if (self->unk50 < 0x14) {
        switch (self->unk50) {
        case 0xa:
            if (!(fs->unk50 & 1)) {
                left = 0;
                right = 0;
                f32 scalar;
                s32 arg6;
                i = 0;
                do {
                    id20.v = (s8)i;
                    AiFighterState* other = fn_27_1F1F58(&id20.v);
                    if (i != self->fighterId && !(other->unk50 & 0x8000) && other->unkCC != fs->unkCC) {
                        if (other->vector5C.m_x > fs->vector5C.m_x) {
                            right++;
                        } else {
                            left++;
                        }
                    }
                } while (++i < 7);
                if (right > left) {
                    scalar = 1.0f;
                } else if (right < left) {
                    scalar = -1.0f;
                } else if (fs->vector5C.m_x >= 0.0f) {
                    scalar = 1.0f;
                } else {
                    scalar = -1.0f;
                }
                if (fs->unkA0 * scalar > 0.0f) {
                    if ((s8)self->level > 0x28 &&
                        fn_27_20BCBC(fs, &fs->vector5C, -scalar) > 20.0f &&
                        (lvA = self->level, randf() < 0.009f * (f32)(s8)lvA)) {
                        if (fs->unkA0 * scalar > 0.0f) {
                            arg6 = 0x72;
                        } else {
                            arg6 = 0x71;
                        }
                        id1C.v = -1;
                        fn_27_1F9FBC(self, 2, &id1C.v, arg6, 0);
                        self->unk64 = (u8)(s32)(2.0f + 8.0f * randf());
                        return 1;
                    }
                    self->unk54 = 0;
                    self->unk50++;
                } else {
                    stick->m_x = 0.6f * scalar;
                }
            } else {
                id18.v = -1;
                fn_27_1F9FBC(self, 1, &id18.v, 0, 0);
                return 1;
            }
            break;
        case 0xb:
            if (fn_27_20B63C(fs) != 0) {
                AiFighterState* target = fn_27_1F1F58(&self->targetId);
                if (target->unk78 >= fs->vector5C.m_y &&
                    (lvB = self->level, randf() < 0.008f * (f32)(s8)lvB)) {
                    stick->m_x = -fs->unkA0;
                    stick->m_y = 1.0f;
                    self->unk54 = 0;
                    self->unk50++;
                } else {
                    finish(self, buttons);
                }
            } else if (self->unk54 > 0x1e) {
                id14.v = -1;
                fn_27_1F9FBC(self, 1, &id14.v, 0, 0);
                return 1;
            }
            break;
        case 0xc:
            stick->m_x = -fs->unkA0;
            stick->m_y = 1.0f;
            if (fs->unk50 & 1) {
                if (fs->unk84 < 0.0f) {
                    self->unk50++;
                }
            } else if (self->unk54 > 0x1e) {
                id10.v = -1;
                fn_27_1F9FBC(self, 1, &id10.v, 0, 0);
                return 1;
            }
            break;
        case 0xd:
            finish(self, buttons);
            break;
        }
    } else {
        if (!(fs->unk50 & 0x800)) {
            idC.v = -1;
            fn_27_1F9FBC(self, 1, &idC.v, 0, 0);
            return 1;
        }
        if (self->script->action != 0x1130) {
            fn_27_1FD190(self);
            id8.v = -1;
            fn_27_20DB40(self->script, 0x1130, &id8.v, 0, 0);
        }
    }
    return 1;
}
