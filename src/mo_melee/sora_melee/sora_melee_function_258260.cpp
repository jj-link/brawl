#include <gm/gm_global.h>
#include <gf/gf_pad_system.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" void fn_8011058C(void*);
extern "C" void fn_27_10C280(ftManager*, int, int);
extern "C" unsigned char lbl_27_data_532F8[];

extern "C" void fn_27_258260() {
    unsigned char* base = (unsigned char*)g_GameGlobal->m_modeMelee;
    int controller = base[0x9f];
    if (controller != 0) {
        int temp = controller - 1;
        int index = 3;
        if (temp <= 3) index = temp;
        unsigned char* order = lbl_27_data_532F8 + index * 3 + 1;
        int changed = 0;
        for (int player = 1; player < 4; player++, order++) {
            gmPlayerInitData* slot = &g_GameGlobal->m_modeMelee->m_playersInitData[player];
            if (slot->m_state == 3) {
                *(unsigned char*)&slot->m_controllerNo = 0;
                slot->_0x3C[1] = 0;
                continue;
            }
            int preferred = order[-1];
            gfPadStatus status1;
            if (*(unsigned char*)&slot->m_controllerNo != preferred + 1 &&
                (g_gfPadSystem->getSysPadStatus(preferred, &status1), status1.m_error == 0)) {
                changed = 1;
                slot->_0x3C[1] = preferred + 1;
                *(unsigned char*)&slot->m_controllerNo = preferred + 1;
                break;
            }
            gfPadStatus status2;
            if (*(unsigned char*)&slot->m_controllerNo == 0 ||
                (g_gfPadSystem->getSysPadStatus(*(unsigned char*)&slot->m_controllerNo - 1, &status2), status2.m_error != 0)) {
                unsigned char* p = (unsigned char*)g_GameGlobal->m_modeMelee;
                int mask = 0;
                for (int i = 0; i < 4; i++) {
                    if (p[i * 0x5c + 0x99] != 3) {
                        int c = p[i * 0x5c + 0x9f];
                        if (c >= 5 && c <= 8) mask |= 1 << (c - 5);
                    }
                }
                for (int i = 0; i < 4; i++) {
                    gfPadStatus status3;
                    if (!(mask & (1 << i)) &&
                        (g_gfPadSystem->getSysPadStatus(i + 4, &status3), status3.m_error == 0)) {
                        changed = 1;
                        slot->_0x3C[1] = i + 5;
                        *(unsigned char*)&slot->m_controllerNo = i + 5;
                        break;
                    }
                }
            }
        }
        if (changed) {
            for (int i = 1; i < 4; i++) {
                if (g_GameGlobal->m_modeMelee->m_playersInitData[i].m_state == 1)
                    g_GameGlobal->m_modeMelee->m_playersInitData[i].m_state = 0;
            }
            fn_8011058C(g_GameGlobal->m_modeMelee);
            for (int i = 1; i < 4; i++) {
                if (g_GameGlobal->m_modeMelee->m_playersInitData[i].m_state == 0)
                    g_GameGlobal->m_modeMelee->m_playersInitData[i].m_state = 1;
            }
        }
        for (int player = 1; player < 4; player++) {
            int entry = g_ftManager->getEntryId(player);
            if (entry != -1)
                fn_27_10C280(g_ftManager, entry, ((unsigned char*)g_GameGlobal->m_modeMelee)[player * 0x5c + 0x9f] - 1);
        }
    }
}
