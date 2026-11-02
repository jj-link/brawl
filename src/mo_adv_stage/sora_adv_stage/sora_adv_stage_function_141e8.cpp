#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <snd/snd_id.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_40_1430C(...);
extern "C" char lbl_40_data_2E28[];
extern "C" f32 lbl_40_rodata_1F0;

struct SoundEntry {
    u8 active;
    u8 pad1[3];
    SndID id;
    s32 handle;
    u32 flag;
    f32 vol;
    u8 pad2[0x0C];
};

struct SoundObj {
    u8 pad0[0x0C];
    u32 count;
    SoundEntry* entries;
    SndID* idPtr;
    u8 pad1[0x04];
    s32 counter;
    u8 pad2[0x04];
    u8 flag24;
    u8 pad3[0x03];
    snd3DGenerator* gen;
};

static inline s32 findFreeEntry(SoundObj* self) {
    s32 off;
    s32 idx = 0;
    off = 0;
    for (u32 k = 0; k < self->count; k++) {
        if (((u8*)self->entries)[off] == 0) {
            return idx;
        }
        off += 0x20;
        idx++;
    }
    return -1;
}

extern "C" void fn_40_141E8(SoundObj* self) {
    f32 vol = lbl_40_rodata_1F0;
    for (u32 i = 0; i < self->count; i++) {
        if (self->flag24 != 0) {
            s32 idx = findFreeEntry(self);
            if (idx >= 0) {
                self->flag24 = 0;
                SoundEntry* e = &self->entries[idx];
                s32 h = self->gen->prepareSE(*self->idPtr, -1);
                if (h == -1) {
                    fn_40_1430C(lbl_40_data_2E28, *self->idPtr);
                } else {
                    e->active = 1;
                    e->id = *self->idPtr;
                    e->flag = 1;
                    e->vol = vol;
                    e->handle = h;
                    self->counter = self->counter + 1;
                }
            }
        }
    }
}
