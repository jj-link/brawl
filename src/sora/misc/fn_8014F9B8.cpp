#pragma force_active on
typedef unsigned char u8;

struct nteGlobalData {
    u8 byte0;
    u8 byte1;
    u8 byte2;
};

struct GameGlobal {
    unsigned char padding[0x34];
    nteGlobalData* data;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F9B8(signed char value) {
    g_GameGlobal->data->byte2 = (u8)value;
}
