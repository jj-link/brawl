#include <types.h>
#pragma force_active on

struct AiInput {
    u8 pad0[0x3C];
    u16 flags;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    s8 unk41;
    s8 fighterId;
    u8 unk43;
    void* script;
    u8 pad48[0x12];
    s16 unk5A;
    u8 pad5C[0x18];
    u8 unk74;
    u8 pad75;
    u8 unk76;
    u8 unk77;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    u8 pad84[0x54];
    u8 paramD8;
    u8 paramD9;
    u8 paramDA;
    u8 paramDB;
    u8 padDC[0x34];
    s8 targetId;
    u8 pad111[7];
    f32 value118;
};

struct AiFighterState {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[0x56];
    s16 unkAA;
    u8 padAC[0x34];
    s32 unkE0;
};

struct AiConstantPool {
    f32 f00[34];
    f64 d88;
    f64 d90;
    f32 f98[48];
    f64 d158;
    f64 d160;
    f32 f168[68];
};

struct TargetInfo {
    u8 pad[0x1C];
    u32 unk1C;
};

extern "C" {

s32 randi__Fl(s32);
f32 randf__Fv();
AiFighterState* fn_27_1F1F58(s8*);
void fn_27_210FD0(void*, f32);
extern const AiConstantPool lbl_27_rodata_2CF0;

void fn_27_1FA86C(AiInput* self, TargetInfo* arg1, s32 arg2, s32 arg3) {
    const AiConstantPool* constants = &lbl_27_rodata_2CF0;
    s32 val = arg2;

    if (arg2 <= 0) {
        s32 r = randi__Fl(0x64);
        s32 da;
        if (r < (s32)self->paramDB) {
            da = self->paramDA;
        } else {
            da = 0;
        }
        s32 r2 = randi__Fl(self->paramD9 + 1);
        val = (s16)(self->paramD8 + (da + r2));
    }

    if (self->unk5A == 0 || (s32)self->unk5A > val) {
        self->unk5A = (s16)val;
    }

    if (arg3 != 0) {
        self->flags |= 1;
    }

    if (arg1 != NULL) {
        AiFighterState* fighterState = fn_27_1F1F58(&self->fighterId);
        if (self->unk41 >= 0) {
            AiFighterState* targetState = fn_27_1F1F58(&self->targetId);
            if (!(fighterState->unk50 & 1) && fighterState->unkAA == 0 && arg1->unk1C == (u32)targetState->unkE0) {
                f32 f = self->value118 + (constants->f98[8] + randf__Fv());
                self->value118 = f;
                if (f > constants->f00[17]) {
                    self->value118 = constants->f00[17];
                }
            }
            self->unk41 = -1;
            self->unk40 = 0;
        } else {
            AiFighterState* targetState = fn_27_1F1F58(&self->targetId);
            if (!(fighterState->unk50 & 1) && fighterState->unkAA == 0 && arg1->unk1C == (u32)targetState->unkE0 && self->value118 < constants->f00[4]) {
                self->value118 += constants->f00[8] + randf__Fv();
            }
        }
        fighterState->unkAA++;
        if ((s8)self->unk74 > 0) {
            self->unk74 = 0xD;
        }
        fn_27_210FD0(self->script, constants->f00[32]);
        self->unk78 = constants->f168[11];
        if (self->unk77 != 0) {
            f32 f = self->unk80 - constants->f00[6];
            self->unk80 = f;
            if (f < constants->f00[0]) {
                self->unk80 = constants->f00[0];
            }
            f = self->unk7C + constants->f00[2];
            self->unk7C = f;
            if (f > constants->f00[5]) {
                self->unk7C = constants->f00[5];
            }
        }
    }
}

}
