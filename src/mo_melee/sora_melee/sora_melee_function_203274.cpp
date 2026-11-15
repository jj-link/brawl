#include <mt/mt_prng.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on
struct AiObj { char pad0[0xE0]; f32 unkE0; f32 unkE4; };
struct AiFighter { char pad0[0x50]; s32 unk50; char pad54[8]; f32 unk5C; f32 unk60; char pad64[0x20]; f32 unk84; char pad88[0x34]; void* unkBC; char padC0[0xFA]; u8 unk1BA; };
struct AiInput { char pad0[0x42]; s8 fighterId; char pad43; AiObj* obj; char pad48[4]; s32 mode; s32 phase; s32 timer; char pad58[0xB8]; s8 targetId; };
extern "C" {
extern const f32 lbl_27_rodata_2CF0[];
AiFighter* fn_27_1F1F58(s8* id);
s32 fn_27_1F2CF8(s8* p);
s32 fn_27_1F2CBC(s8* p);
void fn_27_1FD190(AiInput* self);
void fn_27_1F9FBC(AiInput* self, s32 mode, s8* id, u32 script, s32 arg);
f32 fn_27_20BC28(AiFighter* fs, s8* id);
extern s32 fn_27_203274(AiInput* self, f32* out, s32* buttons) {
    const f32* c = lbl_27_rodata_2CF0;
    AiFighter* fs = fn_27_1F1F58(&self->fighterId);
    AiFighter* ts;
    s32 sp10; s32 spC; s32 sp8;
    if (!fn_27_1F2CF8(&self->targetId) || self->targetId == self->fighterId) fn_27_1FD190(self);
    ts = fn_27_1F1F58(&self->targetId);
    switch (self->mode) {
    case 5: case 6: case 7: case 0xB: case 0x16: case 0x7A:
        if (self->phase == 0) self->obj->unkE4 = self->obj->unkE4 + c[147];
        break;
    case 2:
        self->obj->unkE0 = fs->unk5C;
        if (fs->unk60 > ts->unk60) self->obj->unkE4 = c[7] + fs->unk60;
        else self->obj->unkE4 = fs->unk60 - c[7];
        break;
    default:
        self->obj->unkE0 = ts->unk5C;
        self->obj->unkE4 = ts->unk60;
        break;
    }
    switch (self->phase) {
    case 0: {
        f32 t = c[148] * randf();
        self->phase++;
        self->timer = (s32)t;
    }
    case 1:
        if (fs->unk1BA != 8) {
            *(s8*)&sp10 = -1; fn_27_1F9FBC(self, 1, (s8*)&sp10, 0, 0); return 1;
        }
        if (fs->unk60 > self->obj->unkE4) {
            out[1] = c[63];
            if (self->timer > 10) { self->phase = 2; self->timer = 0; }
        } else {
            out[1] = c[8];
            if (c[18] + fs->unk60 > self->obj->unkE4) {
                if (fn_27_1F2CBC(&self->fighterId) == 0) { self->phase = 2; self->timer = 0; }
            } else if (fs->unk50 & 0x04000000) { self->phase = 2; self->timer = 0; }
            else if (self->timer > 10 && (fs->unk84 < c[120] || self->timer > 180)) { self->phase = 2; self->timer = 0; }
        }
        break;
    default:
        goto process_state;
    }
    if (self->phase != 1) {
    process_state:
        if (self->phase == 2) {
            if (fs->unkBC == ts->unkBC) out[0] = fn_27_20BC28(fs, &self->targetId);
            else out[0] = (fs->unk5C < self->obj->unkE0) ? c[8] : c[63];
            if (out[0] > c[0]) self->phase = 3; else self->phase = 4;
        } else if (self->phase == 3) out[0] = c[8];
        else out[0] = c[63];
        *buttons = soController::getButtonMask((soController::PadButton)2);
        if (self->timer > 8) {
            if (fs->unkBC == ts->unkBC) { *(s8*)&spC = -1; fn_27_1F9FBC(self, 1, (s8*)&spC, 0, 0); }
            else { *(s8*)&sp8 = -1; fn_27_1F9FBC(self, 6, (s8*)&sp8, 0, 0); }
            return 1;
        }
    }
    return 1;
}
}