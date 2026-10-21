#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct nteGlobalData {
    char _0[0x86];
    u8 unk86;
    u8 unk87;
};

class GameGlobal {
public:
    char _pad[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" u16 fn_8014FE7C(void) {
    nteGlobalData* temp = g_GameGlobal->m_nteData;
    return (u16)(temp->unk87 + (temp->unk86 << 8));
}
