#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct nteGlobalData {
    u8 _pad[0xf];
    u8 f0f;
    u8 f10;
    u8 f11;
    u8 f12;
};

class GameGlobal {
public:
    u8 _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F888(u32 arg0, u8 arg1, u8 arg2) {
    nteGlobalData* data = g_GameGlobal->m_nteData;
    data->f0f = (u8)(arg0 >> 8);
    data->f10 = (u8)arg0;
    data->f11 = arg1;
    data->f12 = arg2;
}
