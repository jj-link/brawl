// sora/misc/fn_8014F828.cpp
#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;

struct nteGlobalData {
    u8 _pad[0x88];
};

class GameGlobal {
public:
    u8 _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F828(u32 value, s8 arg1, s8 arg2) {
    nteGlobalData* data = g_GameGlobal->m_nteData;
    data->_pad[3] = (u8)((value >> 8) & 0xFF);
    data->_pad[4] = (u8)value;
    data->_pad[5] = (u8)arg1;
    data->_pad[6] = (u8)arg2;
}
