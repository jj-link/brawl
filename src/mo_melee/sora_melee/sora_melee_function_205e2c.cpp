#include <types.h>
#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct LVec2 {
    f32 x;
    f32 y;
};

struct LFighterState {
    char pad0[0x50];
    s32 unk50;
    char pad54[8];
    LVec2 vector5C;
    char pad64[0x3C];
    f32 unkA0;
    char padA4[8];
    s32 unkAC;
    char padB0[0x10A];
    u8 unk1BA;
};

struct LScript {
    char pad0[0x78];
    u16 action;
};

struct LInput {
    char pad0[0x42];
    s8 fighterId;
    char pad43[1];
    LScript* script;
    char pad48[8];
    s32 unk50;
    s32 unk54;
    char pad58[0x40];
    s8 level;
    char pad99[0x77];
    s8 targetId;
    char pad111[2];
    u8 unk113;
};

union LId {
    s8 v;
    s32 w;
};

extern "C" {
LFighterState* fn_27_1F1F58(s8* fighterId);
s8 fn_27_1FE1C0(LInput* self, f32* outValue, s32 argument);
void fn_27_1F9FBC(LInput* self, s32 mode, s8* fighterId, u32 script, s32 argument);
void fn_27_20DB40(LScript* script, u32 action, s8* fighterId, u32 a, s32 b);
s32 fn_27_20B568(LFighterState* fs);
s32 fn_27_20B6AC(LFighterState* fs, u32 mask, s32 id);
f32 fn_27_20BCBC(LFighterState* fs, LVec2* v, f32 value);

s32 fn_27_205E2C(LInput* self, LVec2* stick, u32* buttons) {
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
    f64 d158 = 4503601774854144.0;
    LFighterState* fs = fn_27_1F1F58(&self->fighterId);
    LId sp10;
    LId spC;
    LId sp8;
    s8 lv;
    u8 st = fs->unk1BA;

    if (st != 0xA && st != 0xB) {
        if (fn_27_20B6AC(fs, 4, 1) != 0 && !(fs->unk50 & 1)) {
            lv = self->level;
            if (lv > 0x32 && randf() < 0.00699999975040555f * (f32)lv) {
                sp10.v = -1;
                fn_27_1F9FBC(self, 0x65, &sp10.v, 0x54, 0);
                return 1;
            }
        }
        spC.v = -1;
        fn_27_1F9FBC(self, 1, &spC.v, 0, 0);
        return 1;
    }

    if (fn_27_20B6AC(fs, 2, 0x1B) != 0) {
        s32 t = self->unk54;
        if (t >= (0x50 - (s8)self->level) / 4 && !(t & 1)) {
            if (fn_27_20B568(fs) != 0) {
                *buttons |= soController::getButtonMask((soController::PadButton)0);
            } else {
                stick->y = 1.0f;
            }
        }
    } else if (fn_27_20B6AC(fs, 1, 5) != 0 || fn_27_20B6AC(fs, 1, 0x20) != 0) {
        f32 a;
        f32 b;
        switch (self->unk50) {
        case 0:
            if (self->unk113 == 0x1B || fs->unkAC == 0x20 || randf() < 0.2f) {
                lv = self->level;
                if (randf() < 0.01f * (f32)lv) {
                    self->unk50 = 1;
                } else {
                    self->unk50 = 2;
                    break;
                }
            } else {
                self->unk50 = 3;
                break;
            }
            /* fallthrough */
        case 1:
            if (!(fs->unk50 & 1) && self->unk54 < 8) {
                a = fn_27_20BCBC(fs, &fs->vector5C, fs->unkA0);
                b = fn_27_20BCBC(fs, &fs->vector5C, -fs->unkA0);
                if (a > b) {
                    stick->x = -0.5f * fs->unkA0;
                    break;
                }
                self->unk50++;
            } else {
                self->unk50++;
            }
            break;
        }

        s32 t54;
        s32 half;
        s32 mode = self->unk50;
        if (mode > 1) {
            t54 = self->unk54;
            half = (0x46 - (s8)self->level) / 2;
            if (t54 >= half && !(t54 & 1)) {
                if (mode != 3) {
                    *buttons |= soController::getButtonMask((soController::PadButton)0);
                } else {
                    stick->y = -1.0f;
                }
            }
        }
    } else if (self->script->action != 0x1120) {
        self->targetId = fn_27_1FE1C0(self, 0, 0);
        sp8.v = -1;
        fn_27_20DB40(self->script, 0x1120, &sp8.v, 0, 0);
    }
    return 1;
}
}
