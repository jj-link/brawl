#include <types.h>
#include <mt/mt_prng.h>

#pragma force_active on
#pragma pool_data on
#pragma pool_fp_consts on

struct StageBounds {
    char pad00[0x18];
    float x0;
    float y0;
    float x1;
    float y1;
};

struct FighterState {
    char pad00[0x50];
    s32 flags;
    char pad54[0x08];
    float x;
    float y;
    char pad64[0x58];
    StageBounds* bounds;
};

struct AiInput {
    char pad00[0x42];
    s8 currentTarget;
    char pad43[0x15];
    s16 field58;
    char pad5A[0x3E];
    s8 level;
    char pad99[0x0F];
    float targetDistance;
    char padAC[0x64];
    s8 target;
};

struct AiAction {
    float position;
    float duration;
    char pad08[0x68];
    AiInput* input;
    FighterState* fighter;
    u16 field78;
    char pad7A[2];
    u16 field7C;
    char pad7E[0x16];
    s32 timer;
    char pad98[0x10];
    s32 state;
    s32 frame;
    char padB0[0x2C];
    float direction;
    float targetX;
    float targetY;
};

struct AiManager {
    char pad00[0x370];
    s32 mode;
};

extern const float lbl_27_rodata_3000[];
extern AiManager* g_aiMgr;

extern "C" void fn_27_1FAC54(void*, s32);
extern "C" u8* fn_27_1F2B58(s32);
extern "C" s8 fn_27_1FE1C0(void*, float*, s32);

extern "C" void fn_27_216E40(AiAction* self, float* out)
{
    f32 pool000 = 0.0f;
    f32 pool004 = -1.0f;
    f32 pool008 = 1.0f;
    f32 pool00C = 0.5f;
    f32 pool010 = 1.1754943508222875e-38f;
    f32 pool014 = 9.999999747378752e-05f;
    f32 pool018 = 0.20000000298023224f;
    f32 pool01C = 0.4000000059604645f;
    f32 pool020 = 0.009999999776482582f;
    f64 pool028 = 4503601774854144.0;
    f32 pool030 = 0.699999988079071f;
    f32 pool034 = 0.800000011920929f;
    f32 pool038 = 0.8999999761581421f;
    f32 pool03C = 40.0f;
    f32 pool040 = 20.0f;
    f32 pool044 = -40.0f;
    f32 pool048 = -20.0f;
    f32 pool04C = 0.75f;
    f32 pool050 = 8.0f;
    f32 pool054 = 5.0f;
    f32 pool058 = 30.0f;
    f32 pool05C = 10.0f;
    f32 pool060 = 1.2000000476837158f;
    f32 pool064 = 0.6000000238418579f;
    f32 pool068 = 70.0f;
    f32 pool06C = 80.0f;
    f32 pool070 = 90.0f;
    f32 pool074 = 0.019999999552965164f;
    f32 pool078 = 50.0f;
    f32 pool07C = 150.0f;
    f32 pool080 = 0.004999999888241291f;
    f32 pool084 = 0.10000000149011612f;
    f32 pool088 = 0.006000000052154064f;
    f32 pool08C = 100.0f;
    f32 pool090 = 120.0f;
    f32 pool094 = 15.0f;
    f32 pool098 = 24.0f;
    f32 pool09C = -0.10000000149011612f;
    f32 pool0A0 = -24.0f;
    f32 pool0A4 = 60.0f;
    f32 pool0A8 = 110.0f;
    f32 pool0AC = 0.30000001192092896f;
    f32 pool0B0 = 0.05000000074505806f;
    f32 pool0B4 = 0.15000000596046448f;
    f64 pool0B8 = 4503599627370496.0;
    f32 pool0C0 = 0.9800000190734863f;
    f32 pool0C4 = 0.8500000238418579f;
    f32 pool0C8 = -0.8999999761581421f;
    f32 pool0CC = -0.949999988079071f;
    f32 pool0D0 = 4.0f;
    f32 pool0D4 = 0.0625f;
    f32 pool0D8 = -0.5f;
    f32 pool0DC = -0.800000011920929f;
    f32 pool0E0 = -0.20000000298023224f;
    f32 pool0E4 = 0.008333333767950535f;
    f32 pool0E8 = 0.00800000037997961f;
    f32 pool0EC = -0.4000000059604645f;
    f32 pool0F0 = -0.30000001192092896f;
    f32 pool0F4 = -0.699999988079071f;
    f32 pool0F8 = 1.7999999523162842f;
    f32 pool0FC = 1.399999976158142f;
    f32 pool100 = 1.034999966621399f;
    f32 pool104 = 89128.9609375f;
    f32 pool108 = -0.6000000238418579f;
    f32 pool10C = -10.0f;
    f32 pool110 = -12.0f;
    f32 pool114 = -30.0f;
    f32 pool118 = 2.0f;
    f32 pool11C = -2.0f;
    f32 pool120 = -0.9900000095367432f;
    f32 pool124 = 180.0f;
    f32 pool128 = 0.0033333334140479565f;
    f32 pool12C = -0.03125f;
    f32 pool130 = 1.5f;
    f32 pool134 = 35.0f;
    f32 pool138 = -0.0625f;
    f32 pool13C = 0.25f;
    f32 pool140 = 9999.900390625f;
    f32 pool144 = 0.009499999694526196f;
    f32 pool148 = 0.3499999940395355f;
    f32 pool14C = 0.3799999952316284f;
    f32 pool150 = 14.0f;
    f32 pool154 = 25.0f;
    f32 pool158 = -50.0f;
    f32 pool15C = -300.0f;
    f32 pool160 = -60.0f;
    f32 pool164 = 0.2142857164144516f;
    f32 pool168 = 0.22857142984867096f;
    f32 pool16C = 0.009800000116229057f;
    f32 pool170 = 0.3199999928474426f;
    f32 pool174 = 0.0066000004298985004f;
    f32 pool178 = 16.0f;
    f32 pool17C = 6.0f;
    f32 pool180 = 0.6499999761581421f;
    f32 pool184 = -5.0f;
    f32 pool188 = 0.03333333507180214f;
    f32 pool18C = 10.889999389648438f;
    f32 pool190 = 12.0f;
    f32 pool194 = 0.125f;
    f32 pool198 = 3.1415927410125732f;
    f32 pool19C = -135.0f;
    f32 pool1A0 = 0.3333333432674408f;
    f32 pool1A4 = 0.6666666865348816f;
    f32 pool1A8 = 0.5999999642372131f;
    f32 pool1AC = 0.5666666626930237f;
    f32 pool1B0 = 0.43333330750465393f;
    float value;
    float distance;

    switch (self->state) {
    case 10:
        out[0] = self->direction;
        out[1] = 1.0f;
        if (self->fighter->x < -135.0f) {
            self->input->field58 = 0;
            u16 val = self->field78;
            if (val != 0)
                self->field7C = val;
            self->field78 = 0;
            fn_27_1FAC54(self->input, 0);
        }
        return;

    case 0: {
        FighterState* fighter = self->fighter;
        StageBounds* bounds = fighter->bounds;
        float width = bounds->x1 - bounds->x0;
        if (width < 0.10000000149011612f)
            width = 100.0f;

        float fraction = (fighter->x - bounds->x0) / width;
        if (fraction < 0.3333333432674408f) {
            self->direction = 1.0f;
            value = 0.4000000059604645f + 0.5f * randf();
        } else if (fraction > 0.6666666865348816f) {
            self->direction = -1.0f;
            value = 0.5999999642372131f - 0.5f * randf();
        } else {
            float direction;
            if (randf() < 0.5f)
                direction = -1.0f;
            else
                direction = 1.0f;
            self->direction = direction;
            if ((f32)(f64)direction > 0.0f)
                value = 0.5666666626930237f + 0.3333333432674408f * randf();
            else
                value = 0.43333330750465393f - 0.3333333432674408f * randf();
        }
        self->position = value;

        s8 level = self->input->level;
        float random = randf() * 0.800000011920929f;
        self->timer = 120;
        self->state = self->state + 1;
        self->frame = 0;
        self->duration = 120.0f * (0.20000000298023224f + random) *
            (0.20000000298023224f + 0.00800000037997961f * (float)(100 - (s32)level));
    }
    default:
        break;
    }

    if (self->state == 1) {
        if (self->frame < 8)
            out[0] = self->direction * (0.125f * (float)self->frame);
        else
            out[0] = self->direction;

        u8* stage = fn_27_1F2B58(1);
        if (stage != 0) {
            switch (stage[2]) {
            case 2:
                out[0] *= 0.699999988079071f;
                break;
            case 3:
                out[0] *= 0.4000000059604645f;
                break;
            }
        }

        FighterState* fighter = self->fighter;
        StageBounds* bounds = fighter->bounds;
        self->targetX = bounds->x0 + self->position * (bounds->x1 - bounds->x0);
        self->targetY = bounds->y0 + self->position * (bounds->y1 - bounds->y0);
        float targetX = self->targetX;

        if (self->direction > 0.0f) {
            if (fighter->x > targetX)
                self->state = self->state + 1;
        } else if (fighter->x < targetX) {
            self->state = self->state + 1;
        }

        if (self->state > 1)
            self->duration = self->duration + (float)self->frame;
    } else if ((float)self->frame > self->duration) {
        switch (g_aiMgr->mode) {
        case 0x30:
            if (self->direction < 0.0f &&
                !(self->fighter->flags & 1) &&
                self->fighter->y < -5.0f &&
                randf() < 0.8999999761581421f) {
                self->state = 10;
                self->frame = 0;
                out[1] = 1.0f;
                self->timer = 90;
                self->input->field58 = -90;
                return;
            }
            break;
        }

        u16 val = self->field78;
        if (val != 0)
            self->field7C = val;
        self->field78 = 0;
        fn_27_1FAC54(self->input, 0);
    }

    if (self->frame > 24 && fn_27_1F2B58(0) == 0) {
        self->input->target = fn_27_1FE1C0(self->input, &distance, 0);
        AiInput* input = self->input;
        if (input->target != input->currentTarget) {
            float targetDistance = input->targetDistance;
            if (distance < targetDistance) {
                u16 val = self->field78;
                if (val != 0)
                    self->field7C = val;
                self->field78 = 0;
                fn_27_1FAC54(self->input, 0);
            }
        }
    }
}
