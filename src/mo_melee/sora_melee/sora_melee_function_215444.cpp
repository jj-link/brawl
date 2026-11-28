#include <types.h>
#include <so/controller/so_controller_impl.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_prng.h>
#include <mt/mt_common.h>
#include <math.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct AiInput {
    char pad0[0x42];
    s8 unk42;
    char pad43[0x98 - 0x43];
    s8 level;
};

struct AiFighter {
    char pad0[0x50];
    u32 unk50;
    char pad54[0x5C - 0x54];
    f32 unk5C;
    char pad60[0xAC - 0x60];
    s32 unkAC;
    char padB0[0xB4 - 0xB0];
    s32 unkB4;
};

struct PredData {
    char pad0[0x28];
    f32 unk28;
    char pad2C[0x34 - 0x2C];
    f32 x;
    f32 y;
    f32 z;
};

struct PredEntry {
    char pad0[0x8];
    PredData* data;
    s32 unkC;
};

struct AiSelf {
    char pad0[0x70];
    AiInput* input;
    AiFighter* fighter;
    u16 unk78;
    char pad7A[2];
    u16 unk7C;
    char pad7E[0x94 - 0x7E];
    s32 unk94;
    char pad98[0x9C - 0x98];
    u16 unk9C;
    char pad9E[2];
    f32 unkA0;
    char padA4[4];
    s32 state;
    s32 unkAC;
};

extern "C" void fn_27_1FAC54(void* p, s32 arg);
extern "C" s8 fn_27_1FE1C0(AiInput* self, f32* outValue, s32 argument);
extern "C" s32 fn_27_20B668(AiFighter*);
extern "C" PredEntry* fn_27_20C010(AiFighter*);
extern "C" s32 fn_27_210D38(AiSelf*, PredData*);

extern "C" void fn_27_215444(AiSelf* self, f32* out, u32* buttons) {
    f32 k000 = 0.0f, k004 = -1.0f, k008 = 1.0f, k00c = 0.5f;
    f32 k010 = 1.1754943508222875e-38f, k014 = 9.999999747378752e-05f, k018 = 0.20000000298023224f, k01c = 0.4000000059604645f;
    f32 k020 = 0.009999999776482582f;
    f64 d028 = 4503601774854144.0;
    f32 k030 = 0.699999988079071f, k034 = 0.800000011920929f, k038 = 0.8999999761581421f, k03c = 40.0f;
    f32 k040 = 20.0f, k044 = -40.0f, k048 = -20.0f, k04c = 0.75f;
    f32 k050 = 8.0f, k054 = 5.0f, k058 = 30.0f, k05c = 10.0f;
    f32 k060 = 1.2000000476837158f, k064 = 0.6000000238418579f, k068 = 70.0f, k06c = 80.0f;
    f32 k070 = 90.0f, k074 = 0.019999999552965164f, k078 = 50.0f, k07c = 150.0f;
    f32 k080 = 0.004999999888241291f, k084 = 0.10000000149011612f, k088 = 0.006000000052154064f, k08c = 100.0f;
    f32 k090 = 120.0f, k094 = 15.0f, k098 = 24.0f, k09c = -0.10000000149011612f;
    f32 k0a0 = -24.0f, k0a4 = 60.0f, k0a8 = 110.0f, k0ac = 0.30000001192092896f;
    f32 k0b0 = 0.05000000074505806f, k0b4 = 0.15000000596046448f;
    f64 d0b8 = 4503599627370496.0;
    f32 k0c0 = 0.9800000190734863f, k0c4 = 0.8500000238418579f, k0c8 = -0.8999999761581421f, k0cc = -0.949999988079071f;
    f32 k0d0 = 4.0f, k0d4 = 0.0625f, k0d8 = -0.5f, k0dc = -0.800000011920929f;
    f32 k0e0 = -0.20000000298023224f, k0e4 = 0.008333333767950535f, k0e8 = 0.00800000037997961f, k0ec = -0.4000000059604645f;
    f32 k0f0 = -0.30000001192092896f, k0f4 = -0.699999988079071f, k0f8 = 1.7999999523162842f, k0fc = 1.399999976158142f;
    f32 k100 = 1.034999966621399f, k104 = 89128.9609375f, k108 = -0.6000000238418579f, k10c = -10.0f;
    f32 k110 = -12.0f, k114 = -30.0f, k118 = 2.0f, k11c = -2.0f;
    f32 k120 = -0.9900000095367432f, k124 = 180.0f, k128 = 0.0033333334140479565f, k12c = -0.03125f;
    f32 k130 = 1.5f, k134 = 35.0f, k138 = -0.0625f, k13c = 0.25f;
    f32 k140 = 9999.900390625f, k144 = 0.009499999694526196f, k148 = 0.3499999940395355f, k14c = 0.3799999952316284f;
    f32 k150 = 14.0f, k154 = 25.0f, k158 = -50.0f, k15c = -300.0f;
    f32 k160 = -60.0f, k164 = 0.2142857164144516f, k168 = 0.22857142984867096f, k16c = 0.009800000116229057f;

    switch (self->state) {
    case 0:
        self->unk94 = 12;
        if (self->input->level <= 30) {
            self->state = 2;
        } else {
            self->state = 1;
        }
        self->unkAC = (self->fighter->unk50 & 1) ? 0 : -10;
        break;
    case 1:
    case 2:
        if (self->unkAC >= 0 && !(self->fighter->unk50 & 1)) {
            u16 v = self->unk78;
            if (v != 0)
                self->unk7C = v;
            self->unk78 = 0;
            fn_27_1FAC54(self->input, 0);
            return;
        }
        break;
    case 4:
        out[1] = -1.0f;
        *buttons |= soController::getButtonMask(soController::Pad_Button_Special);
    default:
        if (self->unkAC >= 0) {
            u16 v = self->unk78;
            if (v != 0)
                self->unk7C = v;
            self->unk78 = 0;
            fn_27_1FAC54(self->input, 0);
        }
        return;
    }

    if (fn_27_20B668(self->fighter) == 0)
        return;
    if (self->fighter->unkB4 == 0x49)
        return;

    PredEntry* entry = fn_27_20C010(self->fighter);
    if (entry != NULL) {
        s32 flags = fn_27_210D38(self, entry->data);
        PredData* d = entry->data;
        f32 sq = d->x * d->x + d->y * d->y + d->z * d->z;
        f32 len;
        if ((float)(double)nw4r::math::FAbs(sq) <= 1.1754943508222875e-38f)
            len = 0.0f;
        else
            len = sq * rsqrtf(sq);
        s32 n = (s32)len > 6 ? (s32)len : 6;
        s32 lim = n < 12 ? n : 12;
        if (flags & 0x20) {
            switch (self->fighter->unkAC) {
            case 0:
            case 0x17:
                lim += 2;
                break;
            }
        }
        if (entry->unkC < lim) {
            if (flags & 0x20) {
                self->unk94 = 60;
                self->unk9C = 180;
                self->unkA0 *= 0.8500000238418579f;
                *buttons |= soController::getButtonMask(soController::Pad_Button_Special);
                AiFighter* f = self->fighter;
                switch (f->unkAC) {
                case 0:
                    out[0] = f->unk5C < entry->data->unk28 ? 1.0f : -1.0f;
                    self->state = 3;
                    break;
                case 13:
                    self->state = 3;
                    break;
                default:
                    out[1] = -1.0f;
                    self->state = 4;
                    self->unkAC = -30;
                    break;
                }
            } else {
                *buttons |= soController::getButtonMask(soController::Pad_Button_Guard);
                self->state = 0;
            }
        } else if ((flags & 0x40) && entry->unkC > lim + 4) {
            self->unk94 = 60;
            self->unk9C = 180;
            self->unkA0 *= 0.8500000238418579f;
            *buttons |= soController::getButtonMask(soController::Pad_Button_Special);
            AiFighter* f = self->fighter;
            switch (f->unkAC) {
            case 12:
                self->state = 3;
                break;
            case 0x17:
                out[0] = f->unk5C < entry->data->unk28 ? 1.0f : -1.0f;
                self->state = 3;
                break;
            default:
                out[1] = -1.0f;
                self->state = 4;
                self->unkAC = -30;
                break;
            }
        }
    }

    if (self->state == 1) {
        f32 dist;
        s8 dir = fn_27_1FE1C0(self->input, &dist, 0);
        AiInput* in = self->input;
        if (dir != in->unk42 && dist < 70.0f) {
            s8 level = in->level;
            if (randf() < 0.009800000116229057f * (f32)(s32)level) {
                *buttons |= soController::getButtonMask(soController::Pad_Button_Guard);
                self->state = 0;
            } else {
                self->state++;
            }
        }
    }
}
