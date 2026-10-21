#pragma force_active on

struct NteData {
    unsigned char pad[1];
    unsigned char flag;
};

struct GameGlobal {
    unsigned char pad[0x34];
    NteData* nteData;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
unsigned int fn_8014F6E4() {
    unsigned int v = g_GameGlobal->nteData->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
