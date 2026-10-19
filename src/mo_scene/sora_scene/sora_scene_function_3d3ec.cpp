#include <gm/gm_global.h>
#include <st/loader/st_loader_manager.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_1_3D3EC() {
    if (!g_stLoaderManager) return;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        stLoaderPlayer* p = g_stLoaderManager->m_loaderPlayers[i];
        if (p && g_GameGlobal->m_modeMelee->m_playersInitData[i].m_state == 1) {
            p->_0x54[1] = 0;
        }
    }
}
