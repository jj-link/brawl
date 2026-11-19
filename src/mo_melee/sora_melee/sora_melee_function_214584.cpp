#include <nw4r/ut/ut_algorithm.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct FighterState {
    char pad00[0x50];
    unsigned int flags50;
    char pad54[0x4c];
    float direction;
    char padA4[8];
    int fieldAC;
    int fieldB0;
    int fieldB4;
    char padB8[0x0c];
    float fieldC4;
    char padC8[0xf2];
    unsigned char field1BA;
};

struct FighterInput {
    char pad00[0x98];
    signed char level;
    char pad99[0x77];
    signed char fighterId;
    char pad111[5];
    unsigned short flags116;
};

struct Context {
    float distance;
    float field04;
    float timer;
    char pad0C[0x64];
    FighterInput* input;
    FighterState* fighter;
    unsigned short field78;
    unsigned short field7A;
    unsigned short field7C;
    unsigned short action;
    char pad80[0x14];
    int field94;
    char pad98[0x10];
    int state;
    int count;
};

extern "C" {
FighterState* fn_27_1F1F58(signed char*);
void fn_27_1FAC54(FighterInput*, int);
int fn_27_20B63C(FighterState*);
float fn_27_20B758(FighterState*, signed char*, float);
float fn_27_20BC28(FighterState*, signed char*);
float fn_27_21F05C(signed char*);
unsigned char fn_27_21F0B4(signed char*);
float fn_27_21F10C(signed char*);
unsigned char fn_27_21F164(signed char*);
}

extern "C" void fn_27_214584(Context* self, float* output) {
    float d;
    double dd;
    d = 0.0f;
    d = -1.0f;
    d = 1.0f;
    d = 0.5f;
    d = 1.17549435e-38f;
    d = 0.0001f;
    d = 0.2f;
    d = 0.4f;
    d = 0.01f;
    dd = 4503601774854144.0;
    d = 0.7f;
    d = 0.8f;
    d = 0.9f;
    d = 40.0f;
    d = 20.0f;
    d = -40.0f;
    d = -20.0f;
    d = 0.75f;
    d = 8.0f;
    d = 5.0f;
    d = 30.0f;
    d = 10.0f;
    d = 1.2f;
    d = 0.6f;
    d = 70.0f;
    d = 80.0f;
    d = 90.0f;
    d = 0.02f;
    d = 50.0f;
    d = 150.0f;
    d = 0.005f;
    d = 0.1f;
    d = 0.006f;
    d = 100.0f;
    d = 120.0f;
    d = 15.0f;
    d = 24.0f;
    d = -0.1f;
    d = -24.0f;
    d = 60.0f;
    d = 110.0f;
    d = 0.3f;
    d = 0.05f;
    d = 0.15f;
    dd = 4503599627370496.0;
    d = 0.98f;
    d = 0.85f;
    d = -0.9f;
    d = -0.95f;
    d = 4.0f;
    d = 0.0625f;
    d = -0.5f;
    d = -0.8f;
    d = -0.2f;
    d = 0.00833333377f;
    d = 0.008f;
    d = -0.4f;
    d = -0.3f;
    d = -0.7f;
    d = 1.8f;
    d = 1.4f;
    d = 1.035f;
    d = 89128.96f;
    d = -0.6f;
    d = -10.0f;
    d = -12.0f;
    d = -30.0f;
    d = 2.0f;
    d = -2.0f;
    d = -0.99f;
    d = 180.0f;
    d = 0.0033333334f;
    d = -0.03125f;
    d = 1.5f;
    d = 35.0f;
    d = -0.0625f;
    d = 0.25f;
    d = 9999.9f;
    d = 0.0095f;
    d = 0.35f;
    d = 0.38f;
    d = 14.0f;

    FighterState* target = fn_27_1F1F58(&self->input->fighterId);
    float distance = nw4r::ut::Abs(
        fn_27_20B758(self->fighter, &self->input->fighterId, 0.0f));

    switch (self->state) {
    case 0:
        switch (target->fieldB4) {
        case 0x74:
        case 0x75:
            goto special_setup;
        default:
            goto normal_setup;
        }

    special_setup: {
            self->distance = fn_27_21F10C(&self->input->fighterId);
            self->field04 = 1.0f;
            signed char level = self->input->level;
            float random = 10.0f * randf();
            float scaledLevel = 0.3f * (float)level;
            self->field94 = 300;
            self->timer = 4.0f + (scaledLevel + random);
            if (!(self->input->flags116 & 0x220)) {
                self->distance += 10.0f * randf();
                float extra = 60.0f * randf();
                self->field94 += 120;
                self->timer += 30.0f + extra;
            }
            goto setup_done;
        }

    normal_setup: {
            self->distance = fn_27_21F05C(&self->input->fighterId);
            self->field04 = 0.0f;
            float random = 180.0f * randf();
            self->field94 = 150;
            self->timer = 30.0f + random;
            if (!(self->input->flags116 & 0x220))
                self->distance += 10.0f * randf();
        }

    setup_done:
        if (distance > 60.0f &&
            !(self->fighter->flags50 & 1) &&
            self->fighter->field1BA != 3) {
            signed char level = self->input->level;
            float random = randf();
            float scaledLevel = (float)level;
            if (random < 0.0095f * scaledLevel) {
                self->state = 0x100;
                return;
            }
        }
        self->state++;

    case 0x100:
        if (self->state == 0x100) {
            if (fn_27_20B63C(self->fighter) == 0 && self->count < 8)
                return;
            self->state = 1;
            self->count = 0;
        }

    case 1:
    case 2:
        if (target->field1BA != 4 && target->field1BA != 6) {
            int kind = target->fieldB4;
            if (randf() < 0.2f)
                kind = 0;
            switch (kind) {
            case 0x53:
                self->state = 0x10;
                self->count = -fn_27_21F0B4(&self->input->fighterId);
                break;
            case 0x76:
                self->state = 0x10;
                self->count = -fn_27_21F164(&self->input->fighterId);
                break;
            default: {
                float random = randf();
                if (random < 0.35f)
                    self->action = 0x51;
                else if (random < 0.38f)
                    self->action = 0x53;
                else if (random < 0.4f)
                    self->action = 0x56;
                if (self->field78)
                    self->field7C = self->field78;
                self->field78 = 0;
                fn_27_1FAC54(self->input, 0);
                break;
            }
            }
            if (self->state == 0x10) {
                if (distance < self->distance - 5.0f) {
                    self->state = 0x20;
                    self->count += 4;
                }
                self->field94 = 300;
            }
        } else if (self->state == 1) {
            float margin;
            switch (self->fighter->fieldAC) {
            case 8:
                margin = 14.0f;
                break;
            default:
                margin = 8.0f;
                break;
            }
            if (distance < self->distance + margin) {
                if (distance < self->distance) {
                    if (fn_27_20B63C(self->fighter)) {
                        *output = -1.0f * fn_27_20BC28(
                            self->fighter, &self->input->fighterId);
                        self->state = 3;
                        self->count = 0;
                    }
                } else {
                    self->count = 0;
                    self->state++;
                }
            } else {
                *output = 0.7f * fn_27_20BC28(
                    self->fighter, &self->input->fighterId);
            }
        } else {
            FighterState* fighter = self->fighter;
            float sign = fn_27_20BC28(fighter, &self->input->fighterId);
            if (fighter->direction * sign < 0.0f) {
                *output = -0.5f * fighter->direction;
                return;
            }
            if (!(target->flags50 & 0x20000)) {
                self->timer -= 1.0f;
                if (self->timer < 0.0f) {
                    if (target->field1BA == 6)
                        self->action = 0x601a;
                    if (self->field78)
                        self->field7C = self->field78;
                    self->field78 = 0;
                    fn_27_1FAC54(self->input, 0);
                }
            }
        }
        break;

    case 3:
        *output = -1.0f * fn_27_20BC28(
            self->fighter, &self->input->fighterId);
        if (self->count > 5 && distance > self->distance - 5.0f)
            self->state = 2;
        break;

    default:
        if (self->count > 0) {
            if (self->state == 0x20) {
                self->action = randf() < 0.5f ? 0x3020 : 0x30a0;
                if (self->field78)
                    self->field7C = self->field78;
                self->field78 = 0;
                fn_27_1FAC54(self->input, 0);
            } else {
                self->action = 0x1020;
                if (self->fighter->fieldAC == 8 && self->field04 > 0.5f) {
                    float chance;
                    if (target->fieldC4 < 100.0f)
                        chance = 0.9f;
                    else
                        chance = 0.3f;
                    if (randf() < chance)
                        self->action = 0x1090;
                }
                if (self->field78)
                    self->field7C = self->field78;
                self->field78 = 0;
                fn_27_1FAC54(self->input, 0);
            }
        }
        break;
    }
}
