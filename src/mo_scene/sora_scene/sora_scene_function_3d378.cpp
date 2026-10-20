#pragma force_active on
typedef unsigned char u8;

struct PlayerInitData {
    u8 character;
    u8 state;
    u8 padding[0x5A];
};

struct ModeMelee {
    u8 padding[0x98];
    PlayerInitData players[7];
};

struct PlayerResult {
    u8 padding[0x24];
    u8 character;
    u8 trailing[0x287];
};

struct GameGlobal {
    u8 padding[8];
    ModeMelee* melee;
    u8 padding0C[0x0C];
    PlayerResult* results;
};

struct LoaderManager {
    void* players[7];
};

extern GameGlobal* g_GameGlobal;
extern LoaderManager* g_stLoaderManager;

extern "C" void fn_1_3D378() {
    if (g_stLoaderManager == 0)
        return;

    for (int i = 0; i < 7; ++i) {
        if (g_stLoaderManager->players[i]) {
            PlayerInitData* player = &g_GameGlobal->melee->players[i];
            if (player->state == 0) {
                player->character = g_GameGlobal->results[i].character;
            }
        }
    }
}
