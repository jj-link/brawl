#include <types.h>
#pragma force_active on

struct Entry {
    u8 id;
    u8 value;
    s8 active;
    u8 pad[0x11];
};

struct GameData {
    u8 pad0[4];
    u8 mode;
    u8 pad5[0x17];
    u8 start;
    u8 count;
    u8 pad1e[6];
    Entry entries[1];
};

struct Global {
    u8 pad[0x3c];
    GameData* data;
};

struct State {
    u8 pad[0x14];
    u8 mode;
};

struct Object {
    u8 pad[0x44];
    State* state;
    u8 pad48[0x68];
    int count;
};

struct Result {
    int id;
    u8 value;
    u8 pad[3];
};

extern "C" Global* g_GameGlobal;
extern "C" void* g_IfMngr;
extern "C" const u8 lbl_27_data_4EDEC[];
extern "C" void fn_800DCDDC(void*, Result*, int);

inline u8 convert(int id) {
    bool valid = false;
    if (id >= 0 && id < 0x33) {
        valid = true;
    }
    if (valid) {
        return lbl_27_data_4EDEC[id * 4 + 2];
    }
    return 0x3d;
}

extern "C" void fn_27_248478(Object* self) {
    Result results[36];

    if (self->state->mode == 4) {
        GameData* data = g_GameGlobal->data;
        if (data->mode == 1) {
            Result* dst = results;
            int start = data->start;
            int end = start + data->count;
            int count = 0;
            Entry* entry = data->entries + start;

            for (int i = start; i < end; ++i, ++entry) {
                if (entry->active != 0) {
                    dst->id = convert(entry->id);
                    ++count;
                    dst->value = entry->value;
                    ++dst;
                }
            }

            if (self->count != count) {
                self->count = count;
                if (g_IfMngr) {
                    fn_800DCDDC(g_IfMngr, results, count);
                }
            }
        }
    }
}
