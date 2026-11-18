#include <types.h>
#include <mt/mt_vector.h>
#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on
struct AiFighterState { char pad0[0x50]; u32 unk50; char pad54[0x20]; Vec3f pos; Vec2f vel; char pad88[8]; Vec2f curPos; Vec2f stick; char padA0[0x11A]; u8 unk1BA; };
struct AiParameters { void* unk0; void* unk4; s8 level; };
struct AiInput { char pad0[0x42]; s8 fighterId; char pad43[0xD]; s32 unk50; s32 unk54; char pad58[0x38]; AiParameters parameters; char pad9C[0x74]; s8 targetId; };
extern "C" {
AiFighterState* fn_27_1F1F58(s8*);
void fn_27_1F9FBC(AiInput*, s32, s8*, u32, s32);
void fn_27_1FD190(AiInput*);
s32 fn_27_20B6AC(AiFighterState*, u32, s32);
}
extern "C" int fn_27_204B64(AiInput* self, Vec2f* stick, u32* buttons) {
    f32 k000 = 0.0f, k004 = 50.0f, k008 = 0.6000000238418579f, k00c = -0.6000000238418579f;
    f32 k010 = 10.0f, k014 = 1.5f, k018 = 0.10000000149011612f, k01c = 30.0f;
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
    AiFighterState* me = fn_27_1F1F58(&self->fighterId);
    AiFighterState* tgt = fn_27_1F1F58(&self->targetId);
    if (me->unk1BA != 0xF) {
        s8 id = -1;
        fn_27_1F9FBC(self, 1, &id, 0, 0);
        return 1;
    }
    switch (self->unk50) {
    case 0:
        fn_27_1FD190(self);
        tgt = fn_27_1F1F58(&self->targetId);
        me->stick.m_x = randf() - 0.5f;
        me->stick.m_y = randf() - 0.5f;
        if (fn_27_20B6AC(me, 4, 0x2E)) {
            f32 lv = (s8)self->parameters.level;
            self->unk50 = 2;
            self->unk54 = -50.0f * (1.0f - lv / 100.0f);
            break;
        }
        {
            s32 lv = self->parameters.level / 4;
            self->unk50++;
            self->unk54 = lv - 0x9B;
        }
    case 1:
        if (self->unk54 < 0) break;
        self->unk50++;
    case 2: {
        f32 level = self->parameters.level / 100.0f;
        f32 range = 100.0f - 70.0f * level;
        Vec3f target;
        target.m_x = tgt->pos.m_x;
        target.m_y = tgt->pos.m_y;
        target.m_z = tgt->pos.m_z;
        Vec2f diff = tgt->vel * (25.0f * (level - 0.2f));
        target.m_x += diff.m_x;
        target.m_y += diff.m_y;
        if (fn_27_20B6AC(me, 4, 0x2E)) {
            if (tgt->unk50 & 0x8000) {
                self->unk50 = 0;
                break;
            }
            if (self->fighterId == self->targetId) {
                target.m_x = 0.0f;
                target.m_y = 30.0f;
                target.m_z = 0.0f;
                fn_27_1FD190(self);
            }
        } else if (self->targetId == self->fighterId || (tgt->unk50 & 0x8000)) {
            self->unk50 = 0;
            break;
        }
        Vec3f copy;
        copy.m_x = target.m_x;
        copy.m_y = target.m_y;
        copy.m_z = target.m_z;
        diff.m_x = copy.m_x - me->curPos.m_x;
        diff.m_y = copy.m_y - me->curPos.m_y;
        Vec2f accel;
        Vec2f maxSpd;
        f32 dx = nw4r::ut::Abs(diff.m_x);
        maxSpd.m_x = maxSpd.m_y = 0.3f + 0.7f * level;
        if (dx <= range) {
            accel.m_x = (1.0f + 2.0f * level) / 64.0f;
            maxSpd.m_x = maxSpd.m_x * (1.0f - (0.2f + 0.8f * level) * (1.0f - dx / range));
        } else {
            self->unk54 = 0;
            accel.m_x = (1.0f + 4.0f * level) / 128.0f;
        }
        f32 dy = nw4r::ut::Abs(diff.m_y);
        if (dy <= range) {
            accel.m_y = (1.0f + 2.0f * level) / 64.0f;
            maxSpd.m_y = maxSpd.m_y * (1.0f - (0.2f + 0.8f * level) * (1.0f - dy / range));
        } else {
            self->unk54 = 0;
            accel.m_y = (1.0f + 4.0f * level) / 128.0f;
        }
        if (diff.m_x < 0.0f) {
            me->stick.m_x -= accel.m_x;
            if (me->stick.m_x < -maxSpd.m_x) me->stick.m_x = -maxSpd.m_x;
        } else {
            me->stick.m_x += accel.m_x;
            if (me->stick.m_x > maxSpd.m_x) me->stick.m_x = maxSpd.m_x;
        }
        if (diff.m_y < 0.0f) {
            me->stick.m_y -= accel.m_y;
            if (me->stick.m_y < -maxSpd.m_y) me->stick.m_y = -maxSpd.m_y;
        } else {
            me->stick.m_y += accel.m_y;
            if (me->stick.m_y > maxSpd.m_y) me->stick.m_y = maxSpd.m_y;
        }
        stick->m_x = me->stick.m_x;
        stick->m_y = me->stick.m_y;
        if (fn_27_20B6AC(me, 4, 0x2E)) {
            if (self->unk54 < 0) break;
            f32 r = 50.0f + 100.0f * (1.0f - level);
            if (diff.m_x * diff.m_x + diff.m_y * diff.m_y > r * r) self->unk54 = 0;
            if (self->unk54 > 1.0f + 8.0f * (1.0f - level) &&
                self->fighterId != self->targetId && !(tgt->unk50 & 0x20000)) {
                self->unk50 = self->unk50 + 1;
                self->unk54 = -30.0f * (1.0f - level);
            }
        } else {
            if (self->unk54 > 60.0f - 58.0f * level && !(tgt->unk50 & 0x20000))
                *buttons = soController::getButtonMask(soController::Pad_Button_Attack);
        }
        break;
    }
    case 3:
        if (self->unk54 >= 0) {
            *buttons = soController::getButtonMask(soController::Pad_Button_Attack);
            self->unk50 = 0;
        }
        break;
    }
    return 1;
}
