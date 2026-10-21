#pragma force_active on
struct GameGlobal {
    unsigned char padding[0x38];
    unsigned char* field_38;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" unsigned char fn_801505EC() {
    return g_GameGlobal->field_38[0x1a];
}
