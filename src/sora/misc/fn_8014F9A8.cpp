#pragma force_active on
struct Inner {
    unsigned char padding[2];
    unsigned char field_2;
};
struct GameGlobal {
    unsigned char padding[0x34];
    Inner* field_34;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" unsigned char fn_8014F9A8() {
    return g_GameGlobal->field_34->field_2;
}
