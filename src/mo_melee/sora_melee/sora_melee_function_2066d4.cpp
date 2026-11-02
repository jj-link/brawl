#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on

struct LEnvView {
    u8 pad0[0x40];
    u32 unk40;
};

struct LFighterState {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ char pad54[0x20];
    /* 0x074 */ f32 unk74;
    /* 0x078 */ char pad78[0x34];
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ char padB0[4];
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ char padB8[4];
    /* 0x0BC */ LEnvView* unkBC;
    /* 0x0C0 */ char padC0[8];
    /* 0x0C8 */ s32 unkC8;
    /* 0x0CC */ s32 unkCC;
    /* 0x0D0 */ char padD0[0xEA];
    /* 0x1BA */ u8 unk1BA;
    /* 0x1BB */ char pad1BB[9];
};

struct LInput {
    /* 0x000 */ char pad0[0x3C];
    /* 0x03C */ u16 flags;
    /* 0x03E */ char pad3E[4];
    /* 0x042 */ s8 fighterId;
    /* 0x043 */ char pad43[0x0D];
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ char pad58[0x40];
    /* 0x098 */ s8 level;
    /* 0x099 */ char pad99[0x77];
    /* 0x110 */ s8 targetId;
};

struct LVec2 { f32 x; f32 y; };

struct LQueryPool {
    u8 pad0[0x191C];
    u8 unk191C;
};

struct LMgrView {
    char pad0[0x100];
    void* unk100;
};

union LId {
    s8 v;
    s32 w;
};

extern "C" {
extern const f32 lbl_27_rodata_2CF0[];
extern LMgrView* g_aiMgr;
LFighterState* fn_27_1F1F58(s8* id);
void fn_27_1F9FBC(LInput* self, s32 mode, s8* id, u32 script, s32 argument);
s32 fn_27_1F2E20(LEnvView*, s32);
void* fn_27_1F2B58(s32);
LQueryPool* fn_27_1F8A7C(void);
s32 fn_27_20B63C(LFighterState*);
s32 fn_27_20B6AC(LFighterState*, u32, s32);
s32 fn_27_21C900(void*, void*, s32);

extern s32 fn_27_2066D4(LInput* self, LVec2* stick, u32* buttons) {
    const f32* c = lbl_27_rodata_2CF0;
    LFighterState* fs = fn_27_1F1F58(&self->fighterId);
    s32 flag = 0;
    s32 i;
    f32 v;
    LId id;
    LId t14;
    LId t10;
    LId tC;
    LId t8;

    if (!(self->flags & 4)) {
        s32 level = self->level;
        for (i = 0; i < 7; i++) {
            id.v = (s8)i;
            LFighterState* other = fn_27_1F1F58(&id.v);
            if (i != self->fighterId && other->unkCC != fs->unkCC) {
                if (other->unkB4 == 0xBE) {
                    flag = 1;
                }
                if (!(other->unk50 & 0x8000)) {
                    if (other->unk1BA != 5 || (level >= 0x3C && !(other->unk50 & 1))) {
                        t14.v = -1;
                        fn_27_1F9FBC(self, 1, &t14.v, 0, 0);
                        return 1;
                    }
                }
            }
        }
        if (level > 0x2D) {
            if (fn_27_21C900(g_aiMgr->unk100, &fs->unk74, 0) != 0 || fn_27_1F8A7C()->unk191C != 0) {
                t10.v = -1;
                fn_27_1F9FBC(self, 1, &t10.v, 0, 0);
                return 1;
            }
        }
    }

    if (fn_27_1F2B58(0) != 0) {
        fn_27_1F9FBC(self, 0x66, &self->targetId, 0x90, 0);
        return 1;
    }

    i = 0;
    {
        LEnvView* env = fs->unkBC;
        s32 idx = fs->unkC8;
        if ((env->unk40 & 0x1000) || fn_27_1F2E20(env, idx) != 0) {
            i = 1;
        }
        if (i != 0) {
            tC.v = -1;
            fn_27_1F9FBC(self, 5, &tC.v, 0, 0);
            return 1;
        }
    }

    switch (self->unk50) {
    case 0:
        if (fn_27_20B63C(fs) != 0) {
            switch (fs->unkAC) {
            case 0x1D:
            case 0x1E:
            case 0x1F:
                if (fn_27_20B6AC(fs, 1, -1) != 0 || randf() < c[6]) {
                    stick->y = c[63];
                    *buttons |= soController::getButtonMask((soController::PadButton)1);
                }
                break;
            }
            v = c[54] * randf();
            self->unk50++;
            self->unk54 = (s32)v;
        }
        break;
    case 1:
        if (self->unk54 >= 0) {
            if (flag == 0) {
                f32 r = randf();
                if (r < c[32]) {
                    *buttons |= soController::getButtonMask((soController::PadButton)6);
                } else if (r < c[2]) {
                    *buttons |= soController::getButtonMask((soController::PadButton)7);
                } else if (r < c[25]) {
                    *buttons |= soController::getButtonMask((soController::PadButton)8);
                }
            }
            self->flags &= ~4;
            v = c[155] * randf();
            self->unk50++;
            self->unk54 = (s32)(v - c[30]);
        }
        break;
    default:
        if (self->unk54 >= 0) {
            t8.v = -1;
            fn_27_1F9FBC(self, 1, &t8.v, 0, 0);
            return 1;
        }
        break;
    }
    return 1;
}
}
