#pragma force_active on
typedef unsigned int u32;

struct AdventureData {
    unsigned char padding[0x804];
    u32 flags;
};

struct GameGlobal {
    unsigned char padding[0x24];
    AdventureData* adventure;
};

extern "C" GameGlobal* g_GameGlobal;

struct EndingMenu {
    unsigned char padding[0x12C];
    int state;
};

extern "C" bool fn_37_13D0(EndingMenu* self) {
    if ((g_GameGlobal->adventure->flags >> 31) == 0) {
        return false;
    }

    switch (self->state) {
    case 0:
    case 1:
    case 2:
    case 4:
        return true;
    default:
        return false;
    }
}
