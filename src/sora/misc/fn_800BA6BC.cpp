#include <types.h>
#pragma force_active on

struct GameData {
    u8 padding[0x1528];
    u8 values[128];
};

struct GameGlobal {
    u8 padding[0x24];
    GameData* data;
};

extern GameGlobal* g_GameGlobal;

struct State {
    u8 padding[8];
    s32 values[128];
};

inline void copyValues(State* self, u8* output) {
    for (u32 i = 0; i < 128; ++i) {
        output[i] = self->values[i];
    }
}

extern "C" void fn_800BA6BC(State* self, u32 index) {
    self->values[index] = 2;
    if (index >= 4 && self->values[index - 4] == 0) {
        self->values[index - 4] = 1;
    }
    if (index + 4 < 128 && self->values[index + 4] == 0) {
        self->values[index + 4] = 1;
    }
    copyValues(self, g_GameGlobal->data->values);
}
