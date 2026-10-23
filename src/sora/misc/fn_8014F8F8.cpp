#pragma force_active on
typedef unsigned char u8;

struct Unknown {
    u8 _0[0x30];
};

class GameGlobal {
public:
    u8 _pad[0x34];
    Unknown* m_data;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014F8F8(u8 value) {
    g_GameGlobal->m_data->_0[0x2F] = value;
}
