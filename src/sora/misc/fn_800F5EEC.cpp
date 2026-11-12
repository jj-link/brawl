#include <snd/snd_system.h>
#pragma force_active on

typedef struct Cmd {
    s32 op;
    s32 a;
    s32 b;
} Cmd;

typedef struct Ctx {
    u8 pad0[0x104];
    Cmd list[0x40];
    u32 count;
    s32 curId;
    f32 f40C;
    f32 f410;
    u32 id414;
    s32 handle418;
    s32 pad41C;
    f32 f420;
} Ctx;

extern "C" int fn_80073D08(sndSystem *snd, u32 id);
extern "C" s32 fn_80073D18(sndSystem *snd, s32 id);
extern const f32 lbl_805A2610;
extern const f32 lbl_805A2614;
extern const f32 lbl_805A2630;

extern "C" s32 fn_800F5EEC(Ctx *self, Cmd *cmd, s32 target) {
    u32 cur;
    s32 idx;

    if (cmd == NULL) {
        return 0;
    }
    self->count = 0;
    self->curId = -1;
    self->f410 = lbl_805A2610;
    self->f40C = lbl_805A2614;
    cur = 0xFFFFFFFF;
    idx = 0;

    for (;;) {
        if (cmd->op == -2) {
            break;
        }
        if (cmd->op == -1) {
            if (target == idx) {
                if (cur != 0xFFFFFFFF && self->id414 == 0xFFFFFFFF) {
                    self->id414 = cur;
                    self->f420 = lbl_805A2610;
                    if (self->handle418 < 0 &&
                        ((u32)__cntlzw(fn_80073D08(g_sndSystem, cur)) >> 5) == 0 &&
                        fn_80073D18(g_sndSystem, self->id414) == 0) {
                        self->handle418 = g_sndSystem->loadSoundGroup((SndGroupID)self->id414, 1, true);
                        if (self->handle418 >= 0) {
                            self->f420 = lbl_805A2630;
                        }
                    }
                }
                return 1;
            }
            idx++;
        } else if (idx == target) {
            if (cmd->op == -3) {
                cur = cmd->b;
            } else if (cmd->op == -4) {
                self->f40C = lbl_805A2630 + (f32)cmd->a;
            } else {
                Cmd *dst;
                if (self->count >= 0x40) {
                    return 0;
                }
                dst = &self->list[self->count];
                *dst = *cmd;
                self->count = self->count + 1;
            }
        }
        cmd++;
    }
    return 0;
}
