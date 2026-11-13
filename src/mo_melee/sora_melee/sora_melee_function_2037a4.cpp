#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on

inline float clampValue(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

struct AiEnv { char pad[4]; };

struct AiFighterState {
    char pad0[0x50];
    s32 unk50;
    char pad54[0x0C];
    f32 unk60;
    char pad64[0x10];
    f32 unk74;
    f32 unk78;
    char pad7C[0x08];
    f32 unk84;
    char pad88[0x18];
    f32 unkA0;
    char padA4[4];
    s16 unkA8;
    char padAA[0x0A];
    s32 unkB4;
    char padB8[0x04];
    AiEnv* unkBC;
    char padC0[0x24];
    u8 unkE4[4];
    char padE8[0xC0];
    s32 unk1A8;
};

struct AiQueryEntry {
    char pad0[0x28];
    f32 unk28;
    f32 unk2C;
    char pad30[0x20];
    f32 unk50;
};

struct AiInput {
    char pad0[0x42];
    s8 fighterId;
    char pad43[0x01];
    f32* unk44;
    s32 unk48;
    char pad4C[0x04];
    s32 unk50;
    s32 unk54;
    char pad58[0x2C];
    s32 unk84;
    s16 unk88;
    char pad8A[0x0E];
    s8 unk98;
    char pad99[0x07];
    f32 unkA0;
    char padA4[0x6C];
    s8 targetId;
};

union BcRet {
    u64 ll;
    f32 f;
};

union LId {
    s8 v;
    s32 w;
};

extern "C" {
extern const f32 lbl_27_rodata_2CF0[];
void* fn_27_1F8A7C(void);
AiQueryEntry* fn_27_2192CC(void*, s32);
AiFighterState* fn_27_1F1F58(s8*);
void fn_27_1F9FBC(AiInput*, s32, s8*, u32, s32);
AiEnv* fn_27_21A14C(void*);
s32 fn_27_21A11C(void*);
f32 fn_27_20BC28(AiFighterState*, s8*);
void fn_27_20B9E0(AiFighterState*, f32*, s8*, f32);
s32 fn_27_20B63C(AiFighterState*);
s32 fn_27_20B668(AiFighterState*);
u16 fn_27_20E30C(f32*, u16, u8*, u8*, u8*);
u64 fn_27_22009C(void*, s32);
f32 fn_27_21F244(s8*);
f32 fn_27_21F1BC(s8*);
f32 rsqrtf__Ff(f32);
}

extern "C" s32 fn_27_2037A4(AiInput* self, f32* stick, u32* buttons) {
    const f32* c = lbl_27_rodata_2CF0;
    AiQueryEntry* entry;
    AiFighterState* fs;
    s32 flag;
    u16 act;
    s32 q;
    f32 sp20[2];
    f32 sp34[3];
    f32 sp28[3];
    f32 t;
    f32 ga;
    LId sp10;
    LId spC;
    LId sp8;
    BcRet bc;

    entry = fn_27_2192CC(fn_27_1F8A7C(), self->unk84);
    fs = fn_27_1F1F58(&self->fighterId);
    fn_27_1F1F58(&self->targetId);

    if (self->unk50 == 0) {
        *self->unk44 = c[0];
        self->unk50 = self->unk50 + 1;
    }

    if (self->unk54 > 0x12C || entry == 0 ||
        fn_27_21A14C(entry) != fs->unkBC) {
        sp10.v = -1;
        fn_27_1F9FBC(self, 1, &sp10.v, 0, 0);
        if (self->unk54 > 0x12C) {
            self->unk88 = 0x14;
        }
        return 1;
    }

    if (fs->unk50 & 0x40) {
        spC.v = -1;
        fn_27_1F9FBC(self, 0xD, &spC.v, 0, 0);
        if (self->unk48 == 0xD) {
            self->unk50 = 0xA;
            self->unk88 = 0;
            return 1;
        }
    }

    sp20[0] = entry->unk28 - fs->unk74;
    sp20[1] = entry->unk2C - fs->unk78;
    stick[0] = c[65] * sp20[0];

    if (!(fs->unk50 & 1) && entry->unk2C < fs->unk60 - c[10]) {
        t = c[2];
        if (nw4r::math::FAbs(stick[0]) < t) {
            t = (stick[0] > c[0]) ? t : c[3];
            stick[0] = t;
        }
    }

    if ((s8)self->targetId != (s8)self->fighterId) {
        switch (fn_27_21A11C(entry)) {
        case 0x3C:
        case 0xA:
        case 0x43:
            sp20[0] = sp20[0] - (c[53] + entry->unk50) *
                fn_27_20BC28(fs, &self->targetId);
            stick[0] = c[65] * sp20[0];
            if (nw4r::math::FAbs(stick[0]) < c[39]) {
                stick[0] = c[39] * fs->unkA0;
            }
            break;
        }
    }

    stick[0] = clampValue(stick[0], c[63], c[8]);
    flag = 1;
    bc.ll = fn_27_22009C(fs->unkE4, 0);

    if (!(stick[0] * bc.f < c[0]) && fs->unkB4 != 8) {
        flag = 0;
    }
    if (flag != 0) {
        *self->unk44 = c[0];
    }

    *self->unk44 += c[65];
    if (*self->unk44 > c[8]) {
        *self->unk44 = c[8];
    }

    if (nw4r::math::FAbs(sp20[0]) < c[47]) {
        stick[0] = stick[0] * *self->unk44;
    }

    switch (self->unk50) {
    case 1:
        if (fs->unkA8 > 0) {
            if (!(fs->unk50 & 1) || fs->unk84 < c[0]) {
                if (nw4r::math::FAbs(sp20[0]) < c[1] &&
                    sp20[1] > c[4]) {
                    stick[1] = c[8];
                    self->unk50 = self->unk50 + 1;
                }
            }
        }
        break;
    default: {
        s32 n = self->unk50 + 1;
        self->unk50 = n;
        if (n < 9) {
            stick[1] = c[8];
        } else if (n > 0xB) {
            self->unk50 = 1;
        }
        break;
    }
    }

    switch (fn_27_21A11C(entry)) {
    case 0x37:
    case 0x31:
    case 0xA:
    case 0x43:
    case 0x3C: {
        f32 fb;
        f32 nrm;

        fb = c[19] * (fn_27_21F1BC(&self->fighterId) +
                      c[19] * fn_27_21F244(&self->fighterId));
        fb += c[42] * entry->unk50;
        ga = sp20[0] * sp20[0] + sp20[1] * sp20[1];
        if ((f32)(double)nw4r::math::FAbs(ga) <= c[91]) {
            nrm = c[0];
        } else {
            nrm = ga * rsqrtf__Ff(ga);
        }

        if (nrm - fb < c[4]) {
            act = 0;
            if (!(fs->unk50 & 1)) {
                switch (fn_27_21A11C(entry)) {
                case 0x31:
                    if (randf() < c[32]) {
                        act = fn_27_20E30C(self->unk44, 0x6015, 0, 0, 0);
                    }
                    break;
                case 0x3C:
                case 0xA:
                case 0x43:
                    if (randf() < c[32]) {
                        sp20[0] = sp20[0] + c[46] *
                            fn_27_20BC28(fs, &self->targetId);
                        if ((s8)self->unk98 < 0x2D) {
                            act = fn_27_20E30C(self->unk44, 0x6011, 0, 0, 0);
                        } else if (sp20[0] *
                                   fn_27_20BC28(fs, &self->targetId) > c[0]) {
                            f32 ua = self->unkA0;
                            fn_27_20B9E0(fs, sp34, &self->targetId,
                                         c[19] * ua);
                            if (sp34[1] > c[17] &&
                                nw4r::math::FAbs(sp34[0] / sp34[1]) < c[42]) {
                                act = fn_27_20E30C(self->unk44, 0x6015, 0, 0, 0);
                            } else {
                                act = fn_27_20E30C(self->unk44, 0x6014, 0, 0, 0);
                            }
                        }
                    }
                    break;
                default:
                    act = fn_27_20E30C(self->unk44, 0x6011, 0, 0, 0);
                    switch (act) {
                    case 0x603C:
                    case 0:
                        act = fn_27_20E30C(self->unk44, 0x6014, 0, 0, 0);
                        if (act == 0) {
                            act = 0x6031;
                        }
                        break;
                    }
                    break;
                }
            } else {
                switch (fn_27_21A11C(entry)) {
                case 0x3C:
                case 0xA:
                case 0x43:
                    sp20[0] = sp20[0] + c[46] *
                        fn_27_20BC28(fs, &self->targetId);
                    if (sp20[0] * fn_27_20BC28(fs, &self->targetId) > c[0]) {
                        f32 ua = self->unkA0;
                        fn_27_20B9E0(fs, sp28, &self->targetId,
                                     c[19] * ua);
                        sp20[0] = entry->unk28 - fs->unk74;
                        sp20[0] = sp20[0] * fs->unkA0;
                        if (sp20[1] > c[52]) {
                            if (sp28[1] > c[17] &&
                                nw4r::math::FAbs(sp28[0] / sp28[1]) < c[42]) {
                                act = 0x6024;
                            }
                        } else if (sp20[1] < c[151]) {
                            if (sp28[1] < c[54] &&
                                nw4r::math::FAbs(sp28[0] / sp28[1]) < c[42]) {
                                act = 0x6025;
                            }
                        } else if (nw4r::math::FAbs(sp28[1]) < c[7]) {
                            if (sp20[0] > c[52]) {
                                act = 0x6022;
                            } else if (sp20[0] < c[151]) {
                                act = 0x6023;
                            }
                        }
                        act = fn_27_20E30C(self->unk44, act, 0, 0, 0);
                    }
                    break;
                default: {
                    u16 k;
                    sp20[0] = sp20[0] * fs->unkA0;
                    if (sp20[1] > c[52]) {
                        k = 0x6024;
                    } else if (sp20[1] < c[151]) {
                        k = 0x6025;
                    } else if (sp20[0] > c[21]) {
                        k = 0x6022;
                    } else if (sp20[0] < c[73]) {
                        k = 0x6023;
                    } else {
                        k = 0x6021;
                    }
                    act = fn_27_20E30C(self->unk44, k, 0, 0, 0);
                    if (act == 0) {
                        act = 0x6041;
                    }
                    break;
                }
                }
            }

            if (act != 0) {
                sp8.v = -1;
                fn_27_1F9FBC(self, 0x65, &sp8.v, act, 0);
                self->unk88 = 5;
            }
        }
        break;
    }
    default:
        if (fn_27_20B63C(fs) != 0 || fn_27_20B668(fs) != 0) {
            q = fn_27_21A11C(entry);
            if (q == -1) {
                f32 gn;
                f32 gb;
                gb = c[19] * (fn_27_21F1BC(&self->fighterId) +
                              c[19] * fn_27_21F244(&self->fighterId));
                gb += c[42] * entry->unk50;
                if (!(self->unk54 & 3)) {
                    ga = sp20[0] * sp20[0] + sp20[1] * sp20[1];
                    if ((f32)(double)nw4r::math::FAbs(ga) <= c[91]) {
                        gn = c[0];
                    } else {
                        gn = ga * rsqrtf__Ff(ga);
                    }
                    if (gn - gb < c[21]) {
                        q = 0;
                    }
                }
            } else {
                if (fs->unk1A8 != fn_27_21A11C(entry)) {
                    q = -1;
                }
            }

            if (q != -1) {
                *buttons = soController::getButtonMask(
                    (soController::PadButton)0);
                self->unk88 = 5;
            }
        }
        break;
    }

    return 1;
}
