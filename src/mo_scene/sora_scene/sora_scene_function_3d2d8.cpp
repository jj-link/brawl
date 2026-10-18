#include <st/loader/st_loader_manager.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_1_3D2D8() {
    if (!g_stLoaderManager) return;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        stLoaderPlayer* p = g_stLoaderManager->m_loaderPlayers[i];
        if (p) p->_0x54[1] = 0;
    }
}
