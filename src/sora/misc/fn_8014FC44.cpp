#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

struct nteGlobalData {
    u8 _pad1F[0x1F];
    u8 unk1F;
    u8 unk20;
    u8 unk21;
    u8 unk22;
};

struct GameGlobal {
    u8 _pad34[0x34];
    nteGlobalData* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014FC44(u16 arg0, u8 arg1, u8 arg2) {
    nteGlobalData* data = g_GameGlobal->m_nteData;
    data->unk1F = (u8)(arg0 >> 8);
    data->unk20 = (u8)arg0;
    data->unk21 = arg1;
    data->unk22 = arg2;
}
