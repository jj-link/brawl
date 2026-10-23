#pragma force_active on
typedef unsigned char u8;

struct nteGlobalData {
    u8 byte0;
    u8 byte1;
};

class GameGlobal {
public:
    u8 _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F700(u8 value) {
    g_GameGlobal->m_nteData->byte1 = value;
}
