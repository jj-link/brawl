#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct NameData {
    u16 values[28];
    u16 a;
    u16 b;
    int c;
};

struct Input {
    u8 pad0[0x50];
    NameData data;
    u8 pad90[0x40];
    int state;
};

struct Menu {
    u8 pad0[0x98];
    int mode;
    int previous;
    u8 padA0[0x368];
    Input* input;
    NameData data;
    int state;
    u8 enabled;
    u8 available;
    u8 updated;
    u8 pad453[0x21];
    u8 active;
    u8 pad475[7];
    int next;
};

struct GameGlobal;

extern "C" {
extern GameGlobal* g_GameGlobal;
int fn_8004D148(GameGlobal*);

int fn_16_51D0(Menu* self) {
    Input* input = self->input;
    int state = input->state;

    if (state == 1)
        return self->previous;

    self->active = 1;
    self->state = state;

    if (state != 0) {
        self->available = 1;
        self->enabled = 0;
    } else {
        self->data = input->data;
        self->enabled = 1;
        self->available = 1;
    }

    self->updated = 1;

    if (self->mode == 3)
        self->available = 0;

    if (fn_8004D148(g_GameGlobal) <= 0)
        self->available = 0;

    if (state == 2) {
        self->next = 12;
        return 13;
    }

    if (state == 5) {
        self->next = 13;
        return 13;
    }

    if (!self->available && !self->enabled)
        return 14;

    return 15;
}
}
