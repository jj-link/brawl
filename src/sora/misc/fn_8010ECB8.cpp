#pragma force_active on

typedef unsigned int u32;

struct GameData {
    char pad[0x6d0];
    signed char flags[1];
};

struct GameGlobal {
    char pad[0x30];
    GameData* p;
};

extern "C" GameGlobal* g_GameGlobal;
extern "C" u32 getStepIndex__19adventureStaticDataFUl(u32);

extern "C" bool fn_8010ECB8(u32 arg) {
    u32 idx = getStepIndex__19adventureStaticDataFUl(arg | 0x2a000100);
    int value = g_GameGlobal->p->flags[idx >> 3];
    int mask = 1 << (idx & 7);
    return (value & mask) != 0;
}
