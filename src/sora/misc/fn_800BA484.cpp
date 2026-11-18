#include <types.h>
#pragma force_active on

struct GameData {
    u8 padding[0x1528];
    u8 values[128];
};

struct GG {
    u8 padding[0x24];
    GameData* data;
};

extern GG* g_GameGlobal;

struct State {
    u8 padding[8];
    s32 values[128];
};

inline void copyValues(State* self, u8* output) {
    for (u32 i = 0; i < 128; ++i) {
        output[i] = self->values[i];
    }
}

extern "C" {
void __dl__FPv(void*);

State* fn_800BA484(State* self, int arg1) {
    if (self != 0) {
        copyValues(self, g_GameGlobal->data->values);
        if (arg1 > 0) __dl__FPv(self);
    }
    return self;
}
}
