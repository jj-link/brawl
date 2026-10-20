#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entry {
    int busy;
    u8 pad[0xB4];
};

struct Menu {
    u8 pad0[0x50];
    int state[2];
    int result[2];
    u8 pad1[0x10C - 0x60];
    int cursor[2];
    int scroll[2];
    int count;
    u8 pad2[0x21C - 0x120];
    Entry entries[2];
};

struct Input {
    u8 pad[0xC];
    u32 buttons;
};

extern "C" {
extern void* g_sndSystem;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_28_870(Menu*, int);

void fn_28_13A8(Menu* self, int index, u32 buttons, Input* input) {
    int cursor = self->cursor[index];
    if (self->entries[index].busy != 0)
        return;

    if (buttons & 8) {
        if (cursor > 0)
            --cursor;
        if (self->cursor[index] == 0 && self->scroll[index] > 0) {
            --self->scroll[index];
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        }
    }

    if (buttons & 4) {
        int limit = self->count < 4 ? self->count : 4;
        if (cursor < limit)
            ++cursor;
        if (limit == self->cursor[index] &&
            self->scroll[index] < self->count - 4) {
            ++self->scroll[index];
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        }
    }

    if (*((u8*)self + 0x349))
        fn_28_870(self, index);

    if (cursor != self->cursor[index]) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        self->cursor[index] = cursor;
    }

    if (input->buttons & 0x100) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
        self->state[index] = 2;
        self->result[index] = 0;
        self->entries[index].busy = 1;
    }

    if (input->buttons & 0x200) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
        self->state[index] = 2;
        self->result[index] = 2;
        self->entries[index].busy = 1;
    }
}
}
