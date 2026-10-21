#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct nteGlobalData {
    u8 pad[0x7F];
    u8 b7f;
    u8 b80;
    u8 b81;
    u8 b82;
};

class GameGlobal {
public:
    u8 _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" s32 fn_8014FA60(void) {
    nteGlobalData* data = g_GameGlobal->m_nteData;
    return data->b82 + (data->b81 << 8) + ((data->b7f << 24) + (data->b80 << 16));
}
