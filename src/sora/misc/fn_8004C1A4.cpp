#include <gm/gm_global.h>
#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern s32 lbl_8059C808;
void fn_8004C63C(GameGlobal* g);
}

struct Rec8A {
    s32 w;
    u8 b;
    u8 pad[3];
};

struct Rec8B {
    s32 w0;
    s32 w1;
};

struct Rec8C {
    u8 b;
    u8 pad[3];
    s32 w;
};

inline void initA(Rec8A* p, Rec8A* end_p) {
    do {
        p->w = -1;
        p->b = 0xFF;
        p++;
    } while (p < end_p);
}

inline void initC(Rec8C* p, Rec8C* end_p) {
    do {
        p->b = 0;
        p->w = -1;
        p++;
    } while (p < end_p);
}

extern "C" void fn_8004C1A4() {
    g_GameGlobal = (GameGlobal*)operator new(0x50, Heaps::GameGlobal);
    g_GameGlobal->m_appData = (gmAppData*)operator new(0x30, Heaps::GameGlobal);
    *(void**)g_GameGlobal->_0 = operator new(8, Heaps::GameGlobal);
    g_GameGlobal->m_modeMelee = (gmGlobalModeMelee*)operator new(0x320, Heaps::GameGlobal);
    *(void**)g_GameGlobal->_1 = operator new(0x5C, Heaps::GameGlobal);
    g_GameGlobal->m_selCharData = (gmSelCharData*)operator new(0x340, Heaps::GameGlobal);
    g_GameGlobal->m_selStageData = (gmSelStageData*)operator new(0x328, Heaps::GameGlobal);
    g_GameGlobal->m_resultInfo = (gmResultInfo*)operator new(0x1388, Heaps::GameGlobal);
    g_GameGlobal->m_setRule = (gmSetRule*)operator new(0x88, Heaps::GameGlobal);
    g_GameGlobal->m_record = (gmGlobalRecord*)operator new(0x3CF0, Heaps::GameGlobal);
    g_GameGlobal->m_nameRecords = (gmGlobalRecord::NameData*)operator new(0x88E0, Heaps::GameGlobal);
    g_GameGlobal->m_tournamentData = (gmTournamentData*)operator new(0x510, Heaps::GameGlobal);

    u8* adv = (u8*)operator new(0x4958, Heaps::GameGlobal);
    if (adv != 0) {
        initA((Rec8A*)(adv + 0x2E0), (Rec8A*)(adv + 0x5F8));
        *(s32*)(adv + 0x4898) = lbl_8059C808;
        *(s32*)(adv + 0x489C) = lbl_8059C808;
        *(s32*)(adv + 0x48A0) = lbl_8059C808;
        *(s32*)(adv + 0x48A4) = lbl_8059C808;
        s32* q = (s32*)(adv + 0x48A8);
        do {
            *q++ = lbl_8059C808;
            *q++ = lbl_8059C808;
        } while (q < (s32*)(adv + 0x48F8));
        *(s32*)(adv + 0x48F8) = 0;
        initC((Rec8C*)(adv + 0x4928), (Rec8C*)(adv + 0x4938));
    }
    g_GameGlobal->m_advData = (gmAdvData*)adv;

    g_GameGlobal->m_nteData = (nteGlobalData*)operator new(0x88, Heaps::GameGlobal);
    *(void**)g_GameGlobal->_4 = operator new(0x20, Heaps::GameGlobal);
    g_GameGlobal->m_corps = (gmGlobalCorps*)operator new(0x2F4, Heaps::GameGlobal);
    g_GameGlobal->m_stageEditData = (gmStageEditData*)operator new(0x24E4, Heaps::GameGlobal);
    g_GameGlobal->m_stageData = (gmStageData*)operator new(0xC14, Heaps::GameGlobal);
    *(void**)g_GameGlobal->_6 = operator new(6, Heaps::GameGlobal);
    *(void**)(g_GameGlobal->_6 + 4) = operator new(5, Heaps::GameGlobal);
    fn_8004C63C(g_GameGlobal);
}