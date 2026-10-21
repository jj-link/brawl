#pragma force_active on
struct GameGlobalInner {
    unsigned char pad[0x18];
    unsigned char flag;
};

struct GameGlobal {
    unsigned char pad[0x38];
    GameGlobalInner* inner;
};

extern GameGlobal* g_GameGlobal;

extern "C" {
unsigned int fn_80150594(void) {
    unsigned int v = g_GameGlobal->inner->flag;
    return (unsigned int)(-v | v) >> 31;
}
}
