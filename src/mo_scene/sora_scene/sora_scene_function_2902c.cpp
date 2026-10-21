#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct Param2902C {
    char _0[0x18];
    int m_unk18;
};

struct Fighters {
    char _0[3];
    u8 m_numFighters;
};

extern "C" void fn_1_2902C(Param2902C* p) {
    gmPlayerInitData* players = g_GameGlobal->m_modeMelee->m_playersInitData;
    Fighters* corps = reinterpret_cast<Fighters*>(g_GameGlobal->m_corps);
    players[0].m_startPointIdx = 0;
    players[1].m_startPointIdx = 1;
    players[2].m_startPointIdx = 2;
    players[3].m_startPointIdx = 3;
    if (p->m_unk18 == 1) {
        if (corps->m_numFighters != 1) {
            players[0].m_startPointIdx = 0;
            players[1].m_startPointIdx = 1;
            players[2].m_startPointIdx = 3;
            players[3].m_startPointIdx = 2;
        }
    } else if (corps->m_numFighters == 1) {
        players[0].m_startPointIdx = 0;
        players[1].m_startPointIdx = 2;
        players[2].m_startPointIdx = 1;
        players[3].m_startPointIdx = 3;
    } else {
        players[0].m_startPointIdx = 0;
        players[1].m_startPointIdx = 2;
        players[2].m_startPointIdx = 3;
        players[3].m_startPointIdx = 1;
    }
}
