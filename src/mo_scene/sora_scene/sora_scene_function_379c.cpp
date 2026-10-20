#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct PlayerInitData {
    u8 character;
    u8 state;
    u8 pad02[3];
    u8 color;
    u8 pad06[0x17];
    u8 flags;
    u8 pad1E[0x3E];
};

struct ModeMelee {
    u8 pad[0x98];
    PlayerInitData players[4];
};

struct GameGlobal {
    u8 pad[8];
    ModeMelee* melee;
};

struct Loader {
    u8 pad[0x57];
    u8 mode;
};

struct LoaderManager {
    Loader* players[4];
};

extern GameGlobal* g_GameGlobal;
extern LoaderManager* g_stLoaderManager;

extern "C" void fn_27_23AC48(Loader*);
extern "C" void fn_27_23BB10(Loader*);

extern "C" void fn_1_379C(int index, u32 character, u32 color) {
    ModeMelee* melee = g_GameGlobal->melee;
    if (character != melee->players[index].character ||
        color != melee->players[index].color) {
        melee->players[index].state = 0;
        melee->players[index].character = character;
        melee->players[index].color = color;
        melee->players[index].flags &= ~0x18;

        Loader* loader = g_stLoaderManager->players[index];
        if (loader)
            fn_27_23AC48(loader);

        loader = g_stLoaderManager->players[index];
        if (loader)
            loader->mode = 1;

        loader = g_stLoaderManager->players[index];
        if (loader)
            fn_27_23BB10(loader);
    }
}
