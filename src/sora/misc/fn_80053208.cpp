#pragma force_active on
struct Inner {
    unsigned char padding[0x32b];
    unsigned char field_32b;
};
struct GameGlobal {
    unsigned char padding[0x24];
    Inner* field_24;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" unsigned char fn_80053208() {
    return g_GameGlobal->field_24->field_32b;
}
