#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

struct NteData {
    u8 pad[0x83];
    u8 byte83;
};

class GameGlobal {
public:
    u8 pad[0x34];
    NteData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014FD80(s32 arg0) {
    NteData* data = g_GameGlobal->m_nteData;
    if (arg0 != 0) {
        data->byte83 |= 1;
    } else {
        data->byte83 &= 0xFE;
    }
}
