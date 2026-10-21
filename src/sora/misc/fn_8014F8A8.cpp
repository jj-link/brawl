#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct nteGlobalData {
    u8 _pad[0x13];
    u8 byte13;
    u8 byte14;
    u8 byte15;
    u8 byte16;
};

class GameGlobal {
public:
    u8 _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F8A8(u32 arg0, u8 arg1, u8 arg2) {
    nteGlobalData* data = g_GameGlobal->m_nteData;
    data->byte13 = (u8)((u16)arg0 >> 8);
    data->byte14 = (u8)arg0;
    data->byte15 = arg1;
    data->byte16 = arg2;
}
