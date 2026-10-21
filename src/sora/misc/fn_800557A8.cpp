#pragma force_active on
struct GameGlobalInner {
    unsigned char pad[0x28];
    unsigned char flags;
};

struct GameGlobal {
    GameGlobalInner* inner;
};

extern GameGlobal* g_GameGlobal;

extern "C" void fn_800557A8() {
    g_GameGlobal->inner->flags |= 0x10;
}
