#include <types.h>
#pragma force_active on

struct Slot {
    u8 flag;
    s8 ids[16];
};

struct Entry {
    u8 b0;
    u8 f : 8;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 rest[25];
};

struct Screen {
    Slot slots[9];
    u8 pad[3];
    Entry entries[10];
    s32 x1DC;
    u8 b1E0[9];
};

extern "C" void fn_8005D5C8(Screen* self) {
    int i;
    int j;
    self->x1DC = 0;
    for (i = 0; i < 9; i++) {
        self->b1E0[i] = 0;
    }
    for (i = 0; i < 9; i++) {
        self->slots[i].flag = 0;
        for (j = 0; j < 16; j++) {
            self->slots[i].ids[j] = -1;
        }
    }
    for (i = 0; i < 10; i++) {
        self->entries[i].f = 0;
        self->entries[i].b3 = 0;
        self->entries[i].b4 = 0;
        self->entries[i].b6 = 0;
    }
}
