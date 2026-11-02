#include <types.h>
#include <ut/ut_relocate.h>
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
extern char lbl_80456688[];

struct Entry {
    s32 first;
    u8 rest[0x24];
};

struct Holder {
    Entry* entries;
    u32 count;
    s32 values[128];
};

extern "C" void fn_800BA57C(Holder* self, u8* buf, u32 size) {
    utRelocate reloc(buf, size);
    self->entries = (Entry*)reloc.getPublicAddress(lbl_80456688);
    self->count = 0;
    while (self->entries[self->count].first >= 0) {
        self->count++;
    }
    if (self->count > 128) {
        self->count = 128;
    }
    u8* src = g_GameGlobal->data->values;
    for (u32 i = 0; i < 128; ++i) {
        self->values[i] = src[i];
    }
}
