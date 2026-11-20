#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_40_1435C(void* self, u32 index);
extern "C" int fn_80079780(snd3DGenerator* gen, s32 handle);
extern "C" int fn_800797A4(snd3DGenerator* gen, s32 handle);
extern "C" f32 lbl_40_rodata_1F0;

struct Entry {
    u8 active;
    u8 pad1[7];
    s32 handle;
    u32 state;
    f32 vol;
    u8 pad2[0x0C];
};

struct Entry2 {
    u8 pad0[5];
    u8 flag5;
    u8 pad1[0x4A];
};

struct Obj {
    u8 pad0[0x0C];
    u32 count;
    Entry* entries;
    Entry2* entries2;
    u8 pad1[0x10];
    snd3DGenerator* gen;
};

extern "C" void fn_40_144E4(Obj* self) {
    f32 vol = lbl_40_rodata_1F0;
    u32 i;
    for (i = 0; i < self->count; i++) {
        Entry* e;
        u8* base = (u8*)self->entries;
        e = (Entry*)(base + i * 0x20);
        if (base[i * 0x20] != 0) {
            switch (e->state) {
            case 1:
                e->vol = vol;
                e->state = 2;
                /* fallthrough */
            case 2:
                if (fn_80079780(self->gen, e->handle) != 0) {
                    fn_40_1435C(self, i);
                    e->state = 3;
                }
                break;
            case 3:
                self->gen->startSE(e->handle, 0);
                e->state = 4;
                break;
            case 4:
            case 5:
                if (fn_800797A4(self->gen, e->handle) == 0) {
                    e->state = 7;
                } else if (((Entry2*)((u8*)self->entries2 + i * 0x50))->flag5 != 0) {
                    fn_40_1435C(self, i);
                }
                break;
            }
        }
    }
}
