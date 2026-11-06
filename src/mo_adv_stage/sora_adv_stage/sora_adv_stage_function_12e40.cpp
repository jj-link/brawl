#include <types.h>
#pragma force_active on

struct Entry {
    u8 pad0[8];
    u32 id;
    u32 type;
    u8 pad1[0x1C - 0x10];
};

struct Cfg {
    u8 pad[0x66];
    u8 count;
    u8 pad67[2];
    u8 flag;
};

struct Self {
    u8 pad[0x90];
    Cfg* cfg;
    Entry* entries;
    u8 pad98[0x14];
    s32 counter;
    u8 padB0[4];
    s32 idx;
};

extern "C" {
void* getInstance__9emManagerFv();
int fn_41_D0A8(void*, u32);
void fn_41_CBD4(void*, u32);
void fn_40_13A10(Self*, Entry*);
}

extern "C" void fn_40_12E40(Self* self) {
    u32 i;
    Entry* e;

    for (i = 0; i < self->cfg->count; i++) {
        e = &self->entries[i];
        if (e->type == 5) {
            if (fn_41_D0A8(getInstance__9emManagerFv(), e->id) != 0) {
                fn_41_CBD4(getInstance__9emManagerFv(), e->id);
                if (self->cfg->flag == 1) {
                    self->counter--;
                }
            }
            e->type = 0;
        }
    }
    if (self->idx >= 0) {
        fn_40_13A10(self, &self->entries[self->idx]);
        self->idx = -1;
    }
}
